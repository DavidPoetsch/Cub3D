/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:05:36 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 14:46:22 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// DRAW GAME INFO
void	draw_fps(t_game *game);
void	draw_player_pos(t_game *game);

// DRAW MAP
int		draw_map(t_game *game);

// DRAW WALL
void	draw_wall(t_game *game, t_raycast *rc);

// RAYCAST
void	raycast(t_game *game);
void	init_raycast(t_player *player, t_raycast *rc);

// RENDER
int		render(t_game *game);

#endif
