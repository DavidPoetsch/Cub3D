/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:46:56 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/17 14:20:21 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int render(t_game *game)
{
	multiplayer(game);
	check_controls(game);
	draw_background(&game->mlx.img, &game->map);
	animate_sprites(&game->map);
	raycast(game);
	draw_map(game);
	if (game->map.sprite_count > 0)
		draw_sprites(game);
	draw_aimbot(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img.ptr, 0, 0);
	move_img_buf(&game->minimap.img, &game->mlx.img, game->minimap.x_offset, game->minimap.y_offset);
	game->delta_sec = get_delta_seconds();
	draw_fps(game);
	draw_player_pos(game);
	return (SUCCESS); 
}
