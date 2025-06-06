/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assign_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:23:53 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/02 14:57:55 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_valid_color(char *str, int *color)
{
	int	value;

	if (is_only_digits(str) && ft_strlen(str) < 4)
	{
		value = ft_atoi(str);
		if (value < 0 || value > 255)
		{
			ft_eprintf("error: color value (%s) out of bounds\n", str);
			return (ERROR);
		}
		*color = value;
		return (SUCCESS);
	}
	ft_eprintf("error: invalid color value (%s)\n", str);
	return (ERROR);
}

static int	assign_channels(char **split, t_color *color)
{
	int	res;

	res = check_valid_color(split[0], &color->r);
	if (res == SUCCESS)
		res = check_valid_color(split[1], &color->g);
	if (res == SUCCESS)
		res = check_valid_color(split[2], &color->b);
	if (res == SUCCESS)
		color->col = (color->r << 16) | (color->g << 8) | color->b;
	return (res);
}

static int	assign_color(char *name, t_textures *textures, t_color *color)
{
	int		res;
	char	**paths;
	char	**split;

	paths = get_paths(name, textures);
	if (!paths)
		return (result_error("texture paths missing"));
	if (paths[1])
	{
		ft_eprintf("Error: too many color inputs for (%s)\n", name);
		return (ERROR);
	}
	split = ft_split(paths[0], ',');
	if (!split)
		return (result_failed("ft_split", __func__, __FILE__));
	if (!split[0] || !split[1] || !split[2] || split[3])
	{
		ft_free_str_lst(&split, true);
		ft_eprintf("Error: invalid color channel input for (%s)\n", name);
		return (ERROR);
	}
	res = assign_channels(split, color);
	ft_free_str_lst(&split, true);
	return (res);
}

static int	assign_all_colors(t_map *map)
{
	int	res;

	res = assign_color("F", map->textures, &map->floor);
	if (res == SUCCESS)
		res = assign_color("C", map->textures, &map->ceiling);
	return (res);
}

int	check_assign_colors(t_map *map)
{
	int	res;

	res = check_colors_exists(map);
	if (res == SUCCESS)
		res = assign_all_colors(map);
	return (res);
}
