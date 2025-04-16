/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:47:56 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/16 14:36:23 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_player_pos(t_game *game)
{
	t_pixel	pos;
	t_pixel	pos_txt;

	pos_txt.x = 38;
	pos_txt.y = 40;
	pos_txt.color = 0x000000;
	pos = new_pxl(pos_txt.x + 20, pos_txt.y, pos_txt.color);
	mlx_set_font(game->mlx.ptr, game->mlx.win, FONT2);
	put_string(game, pos_txt, "x: ");
	put_nbr(game, pos, game->player.pos.x);
	pos.y += 20;
	pos_txt.y += 20;
	put_string(game, pos_txt, "y: ");
	put_nbr(game, pos, game->player.pos.y);
}

void	draw_fps(t_game *game)
{
	t_pixel	pos;
	t_pixel	pos_txt;

	pos_txt.x = 20;
	pos_txt.y = 20;
	pos_txt.color = 0x000000;
	pos = new_pxl(pos_txt.x + 40, pos_txt.y, pos_txt.color);
	mlx_set_font(game->mlx.ptr, game->mlx.win, FONT2);
	put_string(game, pos_txt, "FPS: ");
	put_nbr(game, pos, 1.0 / game->render.delta_seconds);
}
