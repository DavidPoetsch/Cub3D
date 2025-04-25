/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:33:41 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 14:09:12 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_mlx(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx.ptr != NULL && game->minimap.img.ptr != NULL)
	{
		mlx_destroy_image(game->mlx.ptr, game->minimap.img.ptr);
	}
	if (game->mlx.ptr != NULL && game->mlx.img.ptr != NULL)
	{
		mlx_destroy_image(game->mlx.ptr, game->mlx.img.ptr);
	}
	if (game->mlx.ptr != NULL && game->mlx.win != NULL)
	{
		mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	}
	if (game->mlx.ptr != NULL)
	{
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
	}
}
