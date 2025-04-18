/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:57:35 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/18 16:26:29 by lstefane         ###   ########.fr       */
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
	if (arr[y][x] == DOOR)
		map->door_count++;
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

bool is_valid_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (false);
	while(str[i])
	{
		if (is_valid_map_char(str[i]))
		{ 
			ft_eprintf("Error: invalid char (%c) found\n", str[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

int copy_map_arr(t_map *map, char **copy)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->arr[i]);
		if (!copy[i])
			return (result_failed("ft_strdup", __func__, __FILE__));
		if (!is_valid_line(copy[i]))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int is_map_valid(t_map *map)
{
	int	check;
	char **copy;

	if (!map)
		return (ERROR);
	copy = ft_calloc(sizeof(char *), map->height + 1);
	if (!copy)
		return (result_failed("ft_calloc", __func__, __FILE__));
	check = copy_map_arr(map, copy);
	if (check == SUCCESS)
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
	return (SUCCESS);
}

int parse_map(t_game *game, int fd)
{
	int res;

	res = parse_map_lst(&game->map, fd);
	print_map_lst(game->map.lst); //del
	if (res == SUCCESS)
		res = convert_lst_to_arr(&game->map);
	if (res == SUCCESS)
		print_map_arr(game->map.arr); //del
	clear_map_lst(&game->map.lst);
	if (res == SUCCESS)
		res = check_player_start(&game->map, &game->player);
	if (res == SUCCESS)
		res = get_map_width(&game->map);
	if (res == SUCCESS)
		res = is_map_valid(&game->map);
	printf("DOORS: %d\n", game->map.door_count);
	if (res == SUCCESS)
		res = all_textures_exist(&game->map);
	if (res == SUCCESS)
		res = assign_base_textures(game, &game->map);
	if (res == SUCCESS && game->map.door_count > 0)
		res = safe_doors(&game->map);
	if (res == SUCCESS)
		printf("%sMAP IS VALID!%s\n", GREEN_BOLD, RESET);
	else
		printf("%sMAP IS INVALID!%s\n", RED_BOLD, RESET);
	return (res);
}
