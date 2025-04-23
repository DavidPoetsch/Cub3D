/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:29:16 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/23 12:45:11 by dpotsch          ###   ########.fr       */
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

#endif // PLAYER_H
