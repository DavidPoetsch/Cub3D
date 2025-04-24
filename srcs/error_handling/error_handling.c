/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:04:19 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/23 15:21:42 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void free_imgs(t_textures **curr, void *mlx)
{
	int i;

	i = 0;
	while(i < (*curr)->tex_count)
	{
		mlx_destroy_image(mlx, (*curr)->imgs[i].ptr);
		i++;
	}
	free((*curr)->imgs);
}

void	free_texture_lst(t_textures **textures, void *mlx)
{
	t_textures *curr;
	t_textures *next;

	if (!*textures)
		return;
	curr = *textures;
	while(curr)
	{ 
		next = curr->next;
		if (curr->name)
			free(curr->name);
		if (curr->paths)
			ft_free_str_lst(&curr->paths, true);
		if (curr->imgs)
			free_imgs(&curr, mlx);
		free(curr);
		curr = next;
	}
	*textures = NULL;
}

void free_onscreen_textures(t_game *game)
{
	if (game->mlx.ptr != NULL && game->minimap.img.ptr != NULL)
		mlx_destroy_image(game->mlx.ptr, game->minimap.img.ptr);
	if (game->img_defeat.ptr)
		mlx_destroy_image(game->mlx.ptr, game->img_defeat.ptr);
	if (game->img_victory.ptr)
		mlx_destroy_image(game->mlx.ptr, game->img_victory.ptr);
	if (game->img_pistol.ptr)
		mlx_destroy_image(game->mlx.ptr, game->img_pistol.ptr);
	if (game->img_pistol_shot.ptr)
		mlx_destroy_image(game->mlx.ptr, game->img_pistol_shot.ptr);
}

void	free_all(t_game *game)
{
	if (game->map.textures)
		free_texture_lst(&game->map.textures, game->mlx.ptr);
	free_onscreen_textures(game);
	free_mlx(game);
	if (game->map.lst)
		clear_map_lst(&game->map.lst);
	if (game->map.sprite)
		free(game->map.sprite);
	if (game->map.arr)
		ft_free_str_lst(&game->map.arr, true);
	if (game->map.floor)
		free(game->map.floor);
	if (game->map.ceiling)
		free(game->map.ceiling);
	if (game->map.doors)
		free(game->map.doors);
	if (game->dist_buff)
		free(game->dist_buff);
	close_semaphore(&game->filelock, true);
}

void	free_all_exit(t_game *game)
{
	free_all(game);
	exit(EXIT_FAILURE);
}
