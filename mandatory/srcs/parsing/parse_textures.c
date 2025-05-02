/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:56:11 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/02 14:47:10 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_line(t_map *map, char *line)
{
	int			res;
	char		*no_nl;
	char		**split;
	t_textures	*new;

	no_nl = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!no_nl)
		return (result_failed("ft_substr", __func__, __FILE__));
	split = ft_split(no_nl, ' ');
	free(no_nl);
	if (!split)
		return (result_failed("ft_split", __func__, __FILE__));
	if (!split[1])
	{
		ft_free_str_lst(&split, true);
		return (ft_eprintf("Error: invalid arg count in line: %s\n", line));
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

static int	parse_texture_lst(t_map *map, int fd)
{
	int		res;
	char	*line;

	res = SUCCESS;
	while (res == SUCCESS)
	{
		line = get_next_line(fd, GNL);
		if (!line)
			break ;
		if (!is_empty_line(line))
		{
			if (is_map_line(line) == SUCCESS)
			{
				add_to_map_lst(line, &map->lst);
				break ;
			}
			res = check_line(map, line);
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
	if (res != SUCCESS)
		get_next_line(fd, GNL_FREE);
	return (res);
}
