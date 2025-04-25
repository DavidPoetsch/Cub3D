/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lst_to_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:24:45 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 11:46:37 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_lst_size(t_map_lst *map)
{
	int			count;
	t_map_lst	*curr;

	count = 0;
	curr = map;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

int	copy_lst_to_arr(t_map_lst **lst, char ***arr)
{
	int			i;
	t_map_lst	*curr;
	t_map_lst	*next;

	i = 0;
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		if (ft_strchr(curr->line, '\n'))
			(*arr)[i] = ft_substr(curr->line, 0, ft_strlen(curr->line) - 1);
		else
			(*arr)[i] = ft_substr(curr->line, 0, ft_strlen(curr->line));
		if (!(*arr)[i])
		{
			ft_free_str_lst(arr, true);
			return (result_failed("ft_substr", __func__, __FILE__));
		}
		curr = next;
		i++;
	}
	return (SUCCESS);
}

int	convert_lst_to_arr(t_map *map)
{
	int	res;

	res = SUCCESS;
	map->height = get_lst_size(map->lst);
	if (map->height >= MAP_MAX)
		return (result_error("map too big"));
	map->arr = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->arr)
		return (result_failed("ft_calloc", __func__, __FILE__));
	res = copy_lst_to_arr(&map->lst, &map->arr);
	return (SUCCESS);
}
