/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:28 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 11:45:31 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cam			t_cam;
typedef struct s_color		t_color;
typedef struct s_map			t_map;
typedef struct s_mouse		t_mouse;
typedef struct s_player		t_player;
typedef struct s_mlx			t_mlx;
typedef struct s_vec			t_vec;
typedef struct s_game			t_game;
typedef struct s_map_lst	t_map_lst;
typedef struct s_raycast	t_raycast;
typedef struct s_render		t_render;

struct						s_raycast
{
	int						x;
	int						y;
	double					dx;
	double					dy;
};

struct						s_color
{
	int						r;
	int						g;
	int						b;
	int						a;
};

struct					s_map_lst
{
	char			*line;
	t_map_lst	*next;
};

struct					s_map
{
	t_map_lst		*lst;
	t_color			*floor;
	t_color			*ceiling;
	char				*NO_tex;
	char				*SO_tex;
	char				*WE_tex;
	char				*EA_tex;
	char				**arr;
	int					width;
	int					height;
	int					player_x;
	int					player_y;
};

struct						s_vec
{
	double					x;
	double					y;
	double					z;
};

struct						s_mouse
{
	bool					lmb_pressed;
	bool					mmb_pressed;
	bool					rmb_pressed;
	int						last_x;
	int						last_y;
};

struct						s_cam
{
	t_vec					pos;
	t_vec					rotator;
	int						fov;
};

struct						s_player
{
	t_cam					cam;
};

struct						s_mlx
{
	void					*ptr;
	void					*win;
	void					*img;
	int						*buf;
	int						pixel_bits;
	int						line_pixels;
	int						endian;
};

struct s_render
{
	double delta_seconds;
};

struct						s_game
{
	t_map					map;
	t_mlx					mlx;
	t_player				player;
	t_render				render;
};

#endif // STRUCTS_H
