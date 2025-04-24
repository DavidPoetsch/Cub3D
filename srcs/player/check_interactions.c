/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_interactions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:26:24 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 10:33:23 by lstefane         ###   ########.fr       */
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
	if (!game->player.alive || !game->mouse.lmb_pressed)
		return ;
	if (game->player.ammo <= 0)
		return ;
	game->player.pistol_animation = PISTOL_ANIM_TIME;
	game->player.ammo--;
	if (rc->enemy_hit && game->enemy.health > 0)
	{
		game->enemy.health -= 10;
		game->enemy.hit = true;
		ft_printf("Health: %d\n", game->enemy.health);
		if (game->enemy.health <= 0)
			set_enemy_dead(game);
	}
}

void	check_interactions(t_game *game, t_raycast *rc)
{
	check_door_interaction(game, rc);
	check_enemy_hit(game, rc);
	game->mouse.lmb_pressed = 0;
	game->keys.e_pressed = false;
}
