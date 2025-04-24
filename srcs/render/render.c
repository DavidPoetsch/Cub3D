/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:46:56 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 09:52:00 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render(t_game *game)
{
	multiplayer(game);
	check_controls(game);
	draw_background(&game->mlx.img, &game->map);
	animate_sprites(&game->map);
	raycast(game);
	check_interactions(game, &game->aim);
	if (game->map.sprite_count > 0)
		draw_sprites(game);
	draw_crosshair(&game->mlx.img, 10);
	draw_map(game);
	draw_pistol(game);
	draw_win_lose(game);
	draw_ammo(game);
	draw_health(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img.ptr, 0, 0);
	draw_fps(game);
	draw_player_pos(game);
	draw_time_til_restart(game);
	game->delta_sec = get_delta_seconds();
	return (SUCCESS);
}
