/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:05:36 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 14:12:16 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// ANIMATE SPRITES
void	animate_sprites(t_map *sprites);

// DRAW GAME INFO
void	draw_fps(t_game *game);
void	draw_player_pos(t_game *game);
void	draw_crosshair(t_img *img, int size);
void	draw_time_til_restart(t_game *game);

// DRAW MAP
int		draw_map(t_game *game);

// DRAW SPRITES
void	draw_sprites(t_game *game);

// DRAW WALL
void	draw_wall(t_game *game, t_raycast *rc, int x);

// RAYCAST
void	raycast(t_game *game);

// RENDER
int		render(t_game *game);

// WIN LOSE
void	draw_win_lose(t_game *game);

#endif
