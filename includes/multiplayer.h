/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplayer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:38:03 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/17 16:32:58 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTIPLAYER_H
# define MULTIPLAYER_H

void	multiplayer(t_game *game);
void	update_player_pos(t_game *game);
void	read_enemy_pos(t_game *game);
void	check_player_state(t_game *game);
void	update_enemy_pos(t_game *game);

#endif // MULTIPLAYER_H
