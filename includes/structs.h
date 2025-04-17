/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:28 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/17 14:32:25 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_color		t_color;
typedef struct s_map		t_map;
typedef struct s_mouse		t_mouse;
typedef struct s_player		t_player;
typedef struct s_enemy		t_enemy;
typedef struct s_mlx		t_mlx;
typedef struct s_vec		t_vec;
typedef struct s_keys		t_keys;
typedef struct s_game		t_game;
typedef struct s_map_lst	t_map_lst;
typedef struct s_raycast	t_raycast;
typedef struct s_render		t_render;
typedef struct s_img		t_img;
typedef struct s_pixel		t_pixel;
typedef struct s_sprite		t_sprite;
typedef struct s_minimap	t_minimap;

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

struct						s_sprite
{
	int						type;
	t_vec					pos;
	t_vec					relative;
	t_vec					camspace;
	size_t				time;
	size_t				update_t;
	int						t_id;
	int						screenX;
	int						move;
	int						offset;
	int						size;
	int						size_adjust;
	int						draw_start_x;
	int						draw_start_y;
	int						draw_end_x;
	int						draw_end_y;
	double					dist;
	bool					hidden;
	int						tex_x;
	int						tex_y;
	int						tex_count;
	t_img					*texs;
	t_img					*tex;
};

struct						s_raycast
{
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
	int						vertical;
	double				wall_dist;
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

struct						s_map
{
	t_map_lst				*lst;
	t_color					*floor;
	t_color					*ceiling;
	char					*NO_tex_path;
	char					*SO_tex_path;
	char					*WE_tex_path;
	char					*EA_tex_path;
	t_img					NO_tex;
	t_img					SO_tex;
	t_img					WE_tex;
	t_img					EA_tex;
	t_img					D_tex;
	t_sprite			*sprite;
	t_sprite			enemy;
	int						sprite_count;
	char					**arr;
	int						start_x;
	int						start_y;
	int						width;
	int						height;
};

struct						s_mouse
{
	bool					lmb_pressed;
	bool					mmb_pressed;
	bool					rmb_pressed;
	int						last_x;
	int						last_y;
};

struct						s_player
{
	int						start_x;
	int						start_y;
	int						dir;
	t_vec					pos;
	t_vec					rotator;
	t_vec					plane;
	double					fov;
};

struct						s_mlx
{
	void					*ptr;
	void					*win;
	t_img					img;
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

struct						s_minimap
{
	int						tilesize;
	int						x_offset;
	int						y_offset;
	t_img					img;
	double					mini_map_ray_len;
	int						size;
};

struct s_enemy
{
	t_vec			pos;
	t_sprite	sprite;
};

struct						s_game
{
	t_map					map;
	t_minimap				minimap;
	t_mlx					mlx;
	t_player				player;
	t_enemy					enemy;
	t_keys					keys;
	t_raycast				*aim;
	double					delta_sec;
	double *dist_buff; // Window Width
};

#endif // STRUCTS_H
