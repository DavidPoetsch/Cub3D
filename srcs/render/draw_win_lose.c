/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_win_lose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:32:18 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 14:58:31 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_win_lose(t_game *game)
{
	void	*mlx;
	void	*win;
	t_pos	pos;

	if (!game->mlx.ptr || !game->mlx.win)
		return ;
	mlx = game->mlx.ptr;
	win = game->mlx.win;
	pos.x = game->mlx.center.x;
	pos.y = 50;
	if (game->player.health <= 0)
	{
		pos.x -= game->img_defeat.width / 2;
		move_img_buf(&game->img_defeat, &game->mlx.img, pos, true);
	}
	else if (!game->enemy.alive)
	{
		pos.x -= game->img_victory.width / 2;
		move_img_buf(&game->img_victory, &game->mlx.img, pos, true);
	}
}
