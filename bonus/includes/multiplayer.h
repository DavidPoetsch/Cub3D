/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplayer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:38:03 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 14:16:20 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTIPLAYER_H
# define MULTIPLAYER_H

void	multiplayer(t_game *game);
int		init_multiplayer(t_game *game);
void	receive_msg(t_game *game);
void	send_msgs(t_snd_rcv *sr);
void	send_pos(t_game *game);
void	receive_pos(t_game *game);
void	update_enemy_pos(t_game *game);
void	handle_game_state(t_game *game);
void	set_player_dead(t_game *game);
void	send_map_update(t_game *game, int x, int y, char map_char);
void	send_hide_collectable(t_game *game, int x, int y);
void	enqueue_msg(t_snd_rcv *sr, char *msg);
void	msg_hide_collectable(t_game *game, char buf[MSG_SIZE]);

#endif // MULTIPLAYER_H
