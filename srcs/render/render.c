/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:46:56 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/15 17:00:35 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int render(t_game *game)
{
	draw_background(&game->mlx.img, &game->map);
	raycast(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img.ptr, 0, 0);
	game->render.delta_seconds = get_delta_seconds();
	draw_fps(game);
	draw_player_pos(game);
	// usleep(16666);
	// printf("Frames %f\n", 1.0 / game->render.delta_seconds);
	return (SUCCESS); 
}
