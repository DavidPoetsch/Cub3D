/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplayer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:38:03 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/17 14:02:22 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTIPLAYER_H
# define MULTIPLAYER_H

void	update_player_pos(t_game *game);
void	read_enemy_pos(t_game *game);


void update_enemy_pos(t_game *game);

#endif // MULTIPLAYER_H
