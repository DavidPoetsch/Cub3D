/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:57:35 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 15:52:44 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void check_map(t_map *map, char **arr, int x, int y, int *check)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
	{
		*check = ERROR;
		return;
	}
	if (arr[y][x] == WALL || arr[y][x] == 'V')
		return ;
	else
	{
		arr[y][x] = 'V';
		check_map(map, arr, x - 1, y, check);
		check_map(map, arr, x, y - 1, check);
		check_map(map, arr, x - 1, y - 1, check);
		check_map(map, arr, x + 1, y, check);
		check_map(map, arr, x, y + 1, check);
		check_map(map, arr, x + 1, y + 1, check);
		check_map(map, arr, x + 1, y - 1, check);
		check_map(map, arr, x - 1, y + 1, check);
	}
}

char **copy_map_arr(t_map *map)
{
	char **copy;
	int i;

	copy = ft_calloc(sizeof(char *), map->height + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->arr[i]);
		if (!copy[i])
			return (ft_free_str_lst(&copy, true));
		i++;
	}
	return (copy);
}

int is_map_valid(t_map *map)
{
	int	check;
	char **copy;

	if (!map)
		return (ERROR);
	check = SUCCESS;
	copy = copy_map_arr(map);
	if (!copy)
		return result_failed("copy_map_arr", __func__, __FILE__);
	check_map(map, copy, map->start_x, map->start_y, &check);
	ft_free_str_lst(&copy, true);
	return (check);
}

int get_map_width(t_map *map)
{
	int max;
	int width;
	int y;

	if (!map)
		return (ERROR);
	y = 0;
	max = 0;
	while(map->arr[y])
	{
		width = 0;
		while(map->arr[y][width])
		{
			width++;
			if (width > max)
				max = width;
		}
		y++;
	}
	map->width = max;
	//printf("MAP:\n  W: %d\n  H: %d\n",map->width, map->height); //del
	return (SUCCESS);
}

int parse_map(t_game *game, int fd)
{
	int res;

	res = SUCCESS;
	res = parse_map_lst(&game->map, fd);
	print_map_lst(game->map.lst); //del
	if (res == SUCCESS)
		res = convert_lst_to_arr(&game->map);
	if (res == SUCCESS)
		res = check_player_start(&game->map, &game->player);
	if (res == SUCCESS)
		res = get_map_width(&game->map);
	if (res == SUCCESS)
		res = is_map_valid(&game->map); 
	print_map_arr(game->map.arr); //del
	if (res == SUCCESS)
		printf("%sMAP IS VALID!%s\n", GREEN_BOLD, RESET);
	else
		printf("%sMAP IS INVALID!%s\n", RED_BOLD, RESET);
	return (res);
}