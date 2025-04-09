/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lst_to_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:24:45 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/08 16:34:31 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int get_lst_size(t_map_lst *map)
{
	int count;
	t_map_lst *curr;

	count = 0;
	curr = map;
	while(curr)
	{
		count++;
		curr = curr->next;
	}
	return count;
}

void copy_lst_to_arr(t_map_lst **lst, char ***arr)
{
	int				i;
	t_map_lst	*curr;
	t_map_lst	*next;
	
	i = 0;
	curr = *lst;
	while(curr)
	{
		next = curr->next;
		(*arr)[i] = curr->line;
		free(curr);
		curr = next;
		i++;
	}
}

int convert_lst_to_arr(t_map *map)
{
	int count;

	count = get_lst_size(map->lst);
	map->arr = ft_calloc(count + 1, sizeof(char *));
	if (!map->arr)
		return result_failed("ft_calloc", __func__, __FILE__);
	copy_lst_to_arr(&map->lst, &map->arr);
	return (SUCCESS);
}