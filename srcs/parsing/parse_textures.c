/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:56:11 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 14:06:30 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_line(t_map *map, char *line)
{
	int			res;
	char		*no_nl;
	char		**split;
	t_textures	*new;

	no_nl = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!no_nl)
		return (result_failed("ft_substr", __func__, __FILE__));
	split = ft_split(no_nl, ' ');
	if (!split)
		return (result_failed("ft_split", __func__, __FILE__));
	free(no_nl);
	if (!split[1])
	{
		ft_free_str_lst(&split, true);
		return (result_error("invalid argument count"));
	}
	new = create_new_texlst(split);
	if (!new)
	{
		ft_free_str_lst(&split, true);
		return (ERROR);
	}
	res = append_to_texlst(&map->textures, new);
	return (res);
}

int	is_map_line(char *line)
{
	int		res;
	char	**split;

	res = SUCCESS;
	split = ft_split(line, ' ');
	if (!split)
		return (result_failed("ft_split", __func__, __FILE__));
	if (!is_map_element(split[0][0]))
		res = ERROR;
	ft_free_str_lst(&split, true);
	return (res);
}

int	parse_texture_lst(t_map *map, int fd)
{
	int		res;
	char	*line;

	res = SUCCESS;
	while (res == SUCCESS)
	{
		line = get_next_line(fd, GNL);
		if (!line)
			break ;
		if (is_map_line(line) == SUCCESS)
		{
			add_to_map_lst(line, &map->lst);
			break ;
		}
		if (!is_empty_line(line))
		{
			res = check_line(map, line);
			if (res != SUCCESS)
				get_next_line(fd, GNL_FREE);
		}
		free(line);
	}
	if (!line)
		return (result_error("EOF reached no map inside file"));
	return (res);
}

int	parse_textures(t_map *map, int fd)
{
	int	res;

	res = parse_texture_lst(map, fd);
	if (res == SUCCESS)
		res = check_assign_colors(map);
	return (res);
}
