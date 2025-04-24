/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:29:16 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 16:17:07 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

void	init_player(t_player *player);
void	check_interactions(t_game *game, t_raycast *rc);
void	move_door(t_game *game, t_pos pos, bool send_update);
void	move_player_if_in_door(t_game *game, t_pos pos_door);
void	move_player(t_game *game);
void	rotate_player(t_player *player, float angle);

// AMMO
void	collect_ammo(t_game *game, t_sprite *sprite);
void	collect_health(t_game *game, t_sprite *sprite);
void	check_collectables(t_game *game, t_sprite *sprite);
void	reload_gun(t_game *game);

#endif // PLAYER_H
