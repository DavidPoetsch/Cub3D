/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:05:36 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/17 11:56:13 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// ANIMATE SPRITES
void animate_sprites(t_map *sprites);

// DRAW GAME INFO
void	draw_fps(t_game *game);
void	draw_player_pos(t_game *game);

// DRAW MAP
int		draw_map(t_game *game);
void	draw_minimap_ray(t_game *game, t_pixel pxl_center);

// DRAW SPRITES
void	draw_sprites(t_game *game);

// DRAW WALL
void	draw_wall(t_game *game, t_raycast *rc, int x);

// RAYCAST
void	raycast(t_game *game);

// RENDER
int		render(t_game *game);

#endif
