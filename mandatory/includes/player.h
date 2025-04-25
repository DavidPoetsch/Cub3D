/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:29:16 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 14:44:52 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

void	init_player(t_player *player);
void	move_player(t_game *game);
void	rotate_player(t_player *player, float angle);

#endif // PLAYER_H
