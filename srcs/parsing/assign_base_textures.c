/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_base_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:13:52 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/18 16:36:19 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int assign_texture(char *name, t_img *img, t_textures *textures, void *mlx)
{
	int res;
	char **paths;

	paths = get_paths(name, textures);
	if (!paths)
			return (result_error("texture path missing"));
	printf("PATH: %s\n", paths[0]);
	if (!paths[0])
	{
		ft_eprintf("Error: texture path missing for %s\n", name);
		return (ERROR);
	}
	if (paths[1])
	{
		ft_eprintf("Error: texture path missing for %s\n", name);
		return (ERROR);
	}
	res = open_img(mlx, img, paths[0]);
	if (res != SUCCESS)
	{
		ft_eprintf("Error: failed to open texture for %s", name);
		return (ERROR);
	}
	return (res);
}

int assign_base_textures(t_game *game, t_map *map)
{
	int res;

	res = assign_texture("NO", &map->NO_tex, map->textures, game->mlx.ptr);
	if (res == SUCCESS)
		res = assign_texture("SO", &map->SO_tex, map->textures, game->mlx.ptr);
	if (res == SUCCESS)
		res = assign_texture("WE", &map->WE_tex, map->textures, game->mlx.ptr);
	if (res == SUCCESS)
		res = assign_texture("EA", &map->EA_tex, map->textures, game->mlx.ptr);
	if (res == SUCCESS && map->door_count > 0)
		res = assign_texture("D", &map->D_tex, map->textures, game->mlx.ptr);
	if (res == SUCCESS)
		printf("%sALL BASE TEXTURES ASSIGNED!%s\n", GREEN_BOLD, RESET);
	return (res);
}

