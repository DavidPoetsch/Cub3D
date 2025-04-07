/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:28 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/07 12:10:59 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cam t_cam;
typedef struct s_color t_color;
typedef struct s_map t_map;
typedef struct s_mouse t_mouse;
typedef struct s_player t_player;


struct s_color
{
	int			r;
	int			g;
	int			b;
};

struct s_map
{
	/* data */
};

struct s_mouse
{
	bool			lmb_pressed;
	bool			mmb_pressed;
	bool			rmb_pressed;
	int			last_x;
	int			last_y;
};

struct s_cam
{
	/* data */
};

struct s_player
{
	/* data */
};

#endif //STRUCTS_H