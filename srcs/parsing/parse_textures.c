/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:56:11 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/08 16:25:46 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool is_valid_identifier(char *identifier)
{
	if (ft_strncmp(identifier, "NO", 2) == CMP_OK && identifier[2] == '\0')
		return (true);
	else if (ft_strncmp(identifier, "SO", 2) == CMP_OK && identifier[2] == '\0')
		return (true);
	else if (ft_strncmp(identifier, "WE", 2) == CMP_OK && identifier[2] == '\0')
		return (true);
	else if (ft_strncmp(identifier, "EA", 2) == CMP_OK && identifier[2] == '\0')
		return (true);
	else if (ft_strncmp(identifier, "F", 1) == CMP_OK && identifier[1] == '\0')
		return (true);
	else if (ft_strncmp(identifier, "C", 1) == CMP_OK && identifier[1] == '\0')
		return (true);
	return (false);
}

int check_identifier(t_map *map, char **split)
{
	int res;

	if (!is_valid_identifier(split[0]))
	{
		ft_eprintf("error: invalid texture identifier (%s)\n", split[0]);
		return (ERROR);
	}
	res = assign_texture("NO", &map->NO_tex, split);
	if (res != SUCCESS)
		res = assign_texture("SO", &map->SO_tex, split);
	if (res != SUCCESS)
		res = assign_texture("WE", &map->WE_tex, split);
	if (res != SUCCESS)
		res = assign_texture("EA", &map->EA_tex, split);
	if (res != SUCCESS)
		res = assign_color('F', &map->floor, split);
	if (res != SUCCESS)
		res = assign_color('C', &map->ceiling, split);
	return (res);
}

int check_line(t_map *map, char *line)
{
	int res;
	char **split;
	
	res = SUCCESS;
	split = ft_split(line, ' ');
	if (!split)
		return (result_failed("ft_split", __func__, __FILE__));
	if (split[2])
	{
		ft_free_str_lst(&split, true);
		return result_error("too many arguments");
	}
	res = check_identifier(map, split);
	ft_free_str_lst(&split, true);
	return (res);
}

int parse_textures(t_map *map, int fd)
{
	int res;
	int count;
	char *line;

	res = SUCCESS;
	count = 0;
	while (res == SUCCESS && count < 6)
	{
		line = get_next_line(fd, GNL);
		if (!line)
			break;
		if (!is_empty_line(line))
		{
			count++;
			res = check_line(map, line);
			if (res != SUCCESS)
				get_next_line(fd, GNL_FREE);
		}
		free(line);
	}
	if (!line && count != 6)
		return result_error("EOF reached but not all textures assigned");
	return (res);
}
