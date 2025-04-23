/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:04:19 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/22 15:26:03 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_texture_lst(t_textures **textures)
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
		free(curr);
		curr = next;
	}
	*textures = NULL;
}

void	free_all(t_game *game)
{
	free_mlx(game);
	if (game->map.textures)
		free_texture_lst(&game->map.textures);
	if (game->map.lst)
		clear_map_lst(&game->map.lst);
	if (game->map.arr)
		ft_free_str_lst(&game->map.arr, true);
	if (game->map.floor)
		free(game->map.floor);
	if (game->map.ceiling)
		free(game->map.ceiling);
	close_semaphore(&game->filelock, true);
}

void	free_all_exit(t_game *game)
{
	free_all(game);
	exit(EXIT_FAILURE);
}
