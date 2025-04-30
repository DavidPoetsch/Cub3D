/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:52:53 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/30 10:16:38 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_map_lst	*create_new_map_lst(char *line)
{
	t_map_lst	*new;

	new = ft_calloc(1, sizeof(t_map));
	if (!new)
	{
		result_failed("ft_calloc", __func__, __FILE__);
		return (NULL);
	}
	new->line = line;
	new->next = NULL;
	return (new);
}

static int	append_to_map_lst(t_map_lst **map, t_map_lst *new)
{
	t_map_lst	*curr;

	if (!map || !new)
		return (ERROR);
	if (!*map)
	{
		*map = new;
		return (SUCCESS);
	}
	curr = *map;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (SUCCESS);
}

void	clear_map_lst(t_map_lst **map_lst)
{
	t_map_lst	*curr;
	t_map_lst	*next;

	curr = *map_lst;
	while (curr)
	{
		next = curr->next;
		free(curr->line);
		free(curr);
		curr = next;
	}
	*map_lst = NULL;
}

int	add_to_map_lst(char *line, t_map_lst **map)
{
	t_map_lst	*new;
	int			res;

	res = SUCCESS;
	new = create_new_map_lst(line);
	if (!new)
	{
		clear_map_lst(map);
		return (ERROR);
	}
	res = append_to_map_lst(map, new);
	return (res);
}

int	parse_map_lst(t_map *map, int fd)
{
	int		res;
	char	*line;

	res = SUCCESS;
	while (res == SUCCESS)
	{
		line = get_next_line(fd, GNL);
		if (!line)
			break ;
		if (is_empty_line(line))
		{
			if (map->lst)
			{
				get_next_line(fd, GNL_FREE);
				free(line);
				return (result_error("empty line in map"));
			}
			free(line);
			continue ;
		}
		res = add_to_map_lst(line, &map->lst);
		if (res != SUCCESS)
			get_next_line(fd, GNL_FREE);
	}
	return (res);
}
