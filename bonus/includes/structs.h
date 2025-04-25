/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:28 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 12:32:41 by dpotsch          ###   ########.fr       */
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
typedef struct s_pos		t_pos;
typedef struct s_keys		t_keys;
typedef struct s_game		t_game;
typedef struct s_map_lst	t_map_lst;
typedef struct s_raycast	t_raycast;
typedef struct s_render		t_render;
typedef struct s_img		t_img;
typedef struct s_pixel		t_pixel;
typedef struct s_sprite		t_sprite;
typedef struct s_minimap	t_minimap;
typedef struct s_sem		t_sem;
typedef struct s_door		t_door;
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

struct						s_sprite
{
	bool					is_collectable;
	bool					is_anim;
	int						type;
	t_vec					pos;
	t_vec					relative;
	t_vec					camspace;
	size_t					time;
	size_t					update_t;
	int						anim_offset;
	int						t_id;
	int						screen_x;
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
	double					hide_time;
	int						tex_x;
	int						tex_y;
	int						tex_count;
	t_img					*tex;
	t_img					*texs;
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

struct						s_door
{
	t_pos					pos_closed;
	t_pos					pos_opened;
	t_img					*tex;
	int						state;
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
	t_door					*doors;
	t_sprite				*sprite;
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

struct						s_enemy
{
	bool					alive;
	bool					hit;
	double					hit_time;
	t_pos					grid;
	t_pos					grid_old;
	t_vec					pos;
	t_vec					pos_start;
	t_sprite				*sprite;
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
	t_pos					offset;
	t_img					img;
	double					mini_map_ray_len;
	int						size;
};

struct						s_sem
{
	sem_t					*sem;
	int						state;
	char					*name;
};

struct						s_snd_rcv
{
	int						i_buf;
	char					msg_lst[MSG_LST_SIZE][MSG_SIZE];
};

struct						s_game
{
	t_map					map;
	t_minimap				minimap;
	t_mlx					mlx;
	t_player				player;
	t_enemy					enemy;
	t_keys					keys;
	t_raycast				aim;
	t_mouse					mouse;
	double					delta_sec;
	double					*dist_buff;
	t_sem					filelock;
	t_img					*img_victory;
	t_img					*img_lose;
	t_img					*img_pistol;
	t_img					*img_shot;
	size_t					restart_time;
	int						state;
	t_snd_rcv				snd_rcv;
};

#endif // STRUCTS_H
