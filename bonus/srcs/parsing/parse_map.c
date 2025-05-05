/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:57:35 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/05 14:25:57 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_map_width(t_map *map)
{
	int	max;
	int	width;
	t_map_lst *curr;

	if (!map)
		return (ERROR);
	max = 0;
	curr = map->lst;
	while (curr)
	{
		width = 0;
		while (map->lst->line[width])
		{
			width++;
			if (width > max)
				max = width;
		}
		curr = curr->next;
	}
	map->width = max;
	if (map->width >= MAP_MAX)
		return (result_error("map too big"));
	return (SUCCESS);
}

int	parse_map(t_game *game, int fd)
{
	int	res;

	res = parse_map_lst(&game->map, fd);
	if (res == SUCCESS)
		res = get_map_width(&game->map);
	if (res == SUCCESS)
		res = convert_lst_to_arr(&game->map);
	clear_map_lst(&game->map.lst);
	if (res == SUCCESS)
		res = check_player_start(&game->map, &game->player);
	if (res == SUCCESS)
		res = is_map_valid(&game->map);
	if (res == SUCCESS)
		ft_printf("%sMAP IS VALID!%s\n", GREEN_BOLD, RESET);
	else
		ft_printf("%sMAP IS INVALID!%s\n", RED_BOLD, RESET);
	return (res);
}
