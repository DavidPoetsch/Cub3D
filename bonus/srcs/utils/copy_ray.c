/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:29:10 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 15:29:26 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_raycast	copy_ray(t_raycast *rc)
{
	t_raycast	rc_copy;

	rc_copy.map_x = rc->map_x;
	rc_copy.map_y = rc->map_y;
	rc_copy.step_x = rc->step_x;
	rc_copy.step_y = rc->step_y;
	rc_copy.pos = rc->pos;
	rc_copy.cam = rc->cam;
	rc_copy.dir = rc->dir;
	rc_copy.ray_dir = rc->ray_dir;
	rc_copy.plane = rc->plane;
	rc_copy.ray_delta = rc->ray_delta;
	rc_copy.ray_dist = rc->ray_dist;
	rc_copy.wall_hit = rc->wall_hit;
	rc_copy.vertical = rc->vertical;
	rc_copy.wall_dist = rc->wall_dist;
	rc_copy.wall_height = rc->wall_height;
	rc_copy.y_tex_start = rc->y_tex_start;
	rc_copy.y_tex_end = rc->y_tex_end;
	rc_copy.x_tex = rc->x_tex;
	rc_copy.enemy_hit = rc->enemy_hit;
	return (rc_copy);
}
