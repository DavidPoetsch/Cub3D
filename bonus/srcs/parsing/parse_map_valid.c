/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:05:07 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/30 12:10:20 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_boundaries(t_map *map, int x, int y, int *check)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
	{
		*check = ERROR;
		return (ERROR);
	}
	if (map->copy[y][x] == ' ' && *check == SUCCESS)
	{
		ft_eprintf("Error: space found in playable map part\n");
		*check = ERROR;
		return (ERROR);
	}
	return (SUCCESS);
}

static void	check_map(t_map *map, int x, int y, int *check)
{
	if (check_boundaries(map, x, y, check) == ERROR)
		return ;
	if (map->copy[y][x] == DOOR)
		map->door_count++;
	if (map->copy[y][x] == ENEMY)
		map->enemy_count++;
	if (map->copy[y][x] == WALL || map->copy[y][x] == 'V')
		return ;
	else
	{
		map->copy[y][x] = 'V';
		check_map(map, x - 1, y, check);
		check_map(map, x, y - 1, check);
		check_map(map, x - 1, y - 1, check);
		check_map(map, x + 1, y, check);
		check_map(map, x, y + 1, check);
		check_map(map, x + 1, y + 1, check);
		check_map(map, x + 1, y - 1, check);
		check_map(map, x - 1, y + 1, check);
	}
}

static bool	is_valid_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (!is_valid_map_char(str[i]) && str[i] != ' ')
		{
			ft_eprintf("Error: invalid char (%c) found\n", str[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

static int	copy_map_check_line(t_map *map, char **copy)
{
	int	i;

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

int	is_map_valid(t_map *map)
{
	int		check;
	char	**copy;

	if (!map)
		return (ERROR);
	copy = ft_calloc(sizeof(char *), map->height + 1);
	if (!copy)
		return (result_failed("ft_calloc", __func__, __FILE__));
	check = copy_map_check_line(map, copy);
	if (check == SUCCESS)
		map->copy = copy;
	if (check == SUCCESS)
		check_map(map, map->start_x, map->start_y, &check);
	ft_free_str_lst(&copy, true);
	if (map->enemy_count > 1)
		return (result_error("too many enemies found"));
	return (check);
}
