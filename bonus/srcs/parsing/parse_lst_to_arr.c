/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lst_to_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:24:45 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/05 15:27:40 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_lst_size(t_map_lst *map)
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

static int	copy_lst_to_arr(t_map_lst **lst, char ***arr, int width)
{
	int			i;
	t_map_lst	*curr;
	char		*nl;

	i = 0;
	curr = *lst;
	while (curr)
	{
		(*arr)[i] = ft_calloc(width + 1, sizeof(char));
		if (!(*arr)[i])
		{
			ft_free_str_lst(arr, true);
			return (result_failed("ft_substr", __func__, __FILE__));
		}
		ft_strlcpy((*arr)[i], curr->line, width + 1);
		nl = ft_strchr((*arr)[i], '\n');
		if (nl != NULL)
			*nl = '\0';
		curr = curr->next;
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
	res = copy_lst_to_arr(&map->lst, &map->arr, map->width);
	return (res);
}
