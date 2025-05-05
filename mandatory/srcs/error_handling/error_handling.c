/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:04:19 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/05 12:09:25 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_imgs(t_textures **curr, void *mlx)
{
	int	i;

	i = 0;
	while (i < (*curr)->tex_count)
	{
		if ((*curr)->imgs[i].ptr)
			mlx_destroy_image(mlx, (*curr)->imgs[i].ptr);
		i++;
	}
	free((*curr)->imgs);
}

static void	free_texture_lst(t_textures **textures, void *mlx)
{
	t_textures	*curr;
	t_textures	*next;

	if (!*textures)
		return ;
	curr = *textures;
	while (curr)
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

void	free_all(t_game *game)
{
	if (game->map.textures)
		free_texture_lst(&game->map.textures, game->mlx.ptr);
	free_mlx(game);
	if (game->map.lst)
		clear_map_lst(&game->map.lst);
	if (game->map.arr)
		ft_free_str_lst(&game->map.arr, true);
	get_next_line(-1, GNL_FREE_ALL);
}
