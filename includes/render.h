/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:05:36 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 14:44:08 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// ANIMATE SPRITES
void	animate_sprites(t_map *sprites);

// DRAW HITMARKER
void draw_hitmarker(t_game *game);

// DRAW GAME INFO
void	draw_fps(t_game *game);
void	draw_player_pos(t_game *game);
void	draw_crosshair(t_img *img, int size);
void	draw_time_til_restart(t_game *game);
void	draw_ammo(t_game *game);
void	draw_health(t_game *game);

// DRAW MAP
int		draw_map(t_game *game);

// DRAW SPRITES
void	draw_sprites(t_game *game);
void	check_collectables(t_game *game, t_sprite *sprite);

// DRAW SPRITES OBEJCTS
void	draw_sprites_objects(t_game *game);

//DRAW SPRITE TEX
void	draw_sprite_tex(t_sprite *sprite, t_game *game);

// DRAW WALL
void	draw_wall(t_game *game, t_raycast *rc);

// RAYCAST
void	raycast(t_game *game);
void	init_raycast(t_player *player, t_raycast *rc);

// RENDER
int		render(t_game *game);

// WIN LOSE
void	draw_win_lose(t_game *game);

// Draw pistol
void	draw_pistol(t_game *game);

#endif
