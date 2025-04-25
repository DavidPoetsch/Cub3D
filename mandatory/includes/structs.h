/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:28 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 14:49:27 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_color		t_color;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_mlx		t_mlx;
typedef struct s_vec		t_vec;
typedef struct s_pos		t_pos;
typedef struct s_keys		t_keys;
typedef struct s_game		t_game;
typedef struct s_map_lst	t_map_lst;
typedef struct s_raycast	t_raycast;
typedef struct s_render		t_render;
typedef struct s_img		t_img;
typedef struct s_pixel		t_pixel;
typedef struct s_textures	t_textures;
typedef struct s_snd_rcv	t_snd_rcv;
typedef struct s_wall_hit	t_wall_hit;

struct						s_pixel
{
	int						x;
	int						y;
	int						color;
};

struct						s_vec
{
	double					x;
	double					y;
};

struct						s_pos
{
	int						x;
	int						y;
};

struct						s_wall_hit
{
	int						n;
	int						e;
	int						s;
	int						w;
};

struct						s_img
{
	void					*ptr;
	int						*buf;
	int						pixel_bits;
	int						line_pixels;
	int						endian;
	int						width;
	int						height;
};

struct						s_mlx
{
	void					*ptr;
	void					*win;
	t_img					img;
};

struct						s_raycast
{
	int						x;
	int						map_x;
	int						map_y;
	int						step_x;
	int						step_y;
	t_vec					pos;
	t_vec					cam;
	t_vec					dir;
	t_vec					ray_dir;
	t_vec					plane;
	t_vec					ray_delta;
	t_vec					ray_dist;
	bool					wall_hit;
	bool					enemy_hit;
	int						vertical;
	double					wall_dist;
	int						wall_height;
	int						y_tex_start;
	int						y_tex_end;
	int						x_tex;
};

struct						s_color
{
	int						col;
	int						r;
	int						g;
	int						b;
	int						a;
};

struct						s_map_lst
{
	char					*line;
	t_map_lst				*next;
};

struct						s_textures
{
	char					*name;
	char					**paths;
	int						tex_count;
	t_img					*imgs;
	t_textures				*next;
};

struct						s_map
{
	t_map_lst				*lst;
	t_textures				*textures;
	t_color					floor;
	t_color					ceiling;
	t_img					*no_tex;
	t_img					*so_tex;
	t_img					*we_tex;
	t_img					*ea_tex;
	t_img					*d_tex;
	int						curr_sprites;
	int						sprite_count;
	int						door_count;
	char					**arr;
	char					**copy;
	int						start_x;
	int						start_y;
	int						width;
	int						height;
};

struct						s_player
{
	int						health;
	int						start_x;
	int						start_y;
	int						dir;
	t_vec					pos;
	t_vec					rotator;
	t_vec					plane;
	double					pistol_animation;
	int						ammo;
	int						reloads;
};

struct						s_keys
{
	bool					w_pressed;
	bool					s_pressed;
	bool					a_pressed;
	bool					d_pressed;
	bool					e_pressed;
	bool					arrow_right_pressed;
	bool					arrow_left_pressed;
};

struct						s_snd_rcv
{
	int						i_buf;
	char					msg_lst[MSG_LST_SIZE][MSG_SIZE];
};

struct						s_game
{
	t_map					map;
	t_mlx					mlx;
	t_player				player;
	t_keys					keys;
	t_raycast				aim;
	double					delta_sec;
};

#endif // STRUCTS_H
