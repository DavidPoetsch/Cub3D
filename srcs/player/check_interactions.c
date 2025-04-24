/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_interactions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:26:24 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 12:11:51 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_door_interaction(t_game *game, t_raycast *rc)
{
	if (!game->keys.e_pressed)
		return ;
	if (rc->wall_dist > INTERACT_DIST)
		return ;
	if (!is_door(game->map.arr, rc->map_x, rc->map_y))
		return ;
	move_door(game, set_pos(rc->map_x, rc->map_y), true);
}

static void	check_enemy_hit(t_game *game, t_raycast *rc)
{
	if (game->player.health <= 0 || !game->mouse.lmb_pressed)
		return ;
	if (game->player.ammo <= 0)
		return ;
	game->player.pistol_animation = PISTOL_ANIM_TIME;
	game->player.ammo--;
	if (rc->enemy_hit && game->enemy.alive)
	{
		game->enemy.hit = true;
		enqueue_msg(&game->snd_rcv, "hit enemy\n");
	}
}

void	check_interactions(t_game *game, t_raycast *rc)
{
	check_door_interaction(game, rc);
	check_enemy_hit(game, rc);
	game->mouse.lmb_pressed = 0;
	game->keys.e_pressed = false;
}
