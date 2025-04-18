/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplayer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:38:03 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 16:23:31 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTIPLAYER_H
# define MULTIPLAYER_H

void	multiplayer(t_game *game);
void	update_player_pos(t_game *game);
void	read_enemy_pos(t_game *game);
void	check_player_state(t_game *game);
void	update_enemy_pos(t_game *game);
void	restart_game(t_game *game);
void	set_player_alive(t_game *game);
int		send_state(char *msg, bool send_now);
void	send_map_update(t_game *game, int x, int y, char map_char);
void	put_msg_in_send_list(t_snd_rcv *sr, char *msg);

#endif // MULTIPLAYER_H
