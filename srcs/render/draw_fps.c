/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:47:56 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/15 13:15:42 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_player_pos(t_game *game)
{
	t_pixel	pos;

	pos.x = 10;
	pos.y = 40;
	pos.color = 0x000000;
	mlx_set_font(game->mlx.ptr, game->mlx.win, FONT2);
	put_nbr(game, pos, game->player.pos.x);
	pos.x += 20;
	put_nbr(game, pos, game->player.pos.y);
}

void	draw_fps(t_game *game)
{
	t_pixel	pos;

	pos.x = 10;
	pos.y = 20;
	pos.color = 0x000000;
	mlx_set_font(game->mlx.ptr, game->mlx.win, FONT2);
	put_nbr(game, pos, 1.0 / game->render.delta_seconds);
}
