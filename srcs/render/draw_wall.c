/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:54:45 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 14:55:19 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief ### Draw vertical texture line
 *
 * @param game game struct
 * @param rc raycast struct
 * @param x position on screen
 * @param tex texture
 */
void	ver_tex_line(t_game *game, t_raycast *rc, t_img *tex)
{
	t_pixel	pxl;
	double	step;
	double	tex_y;
	int		offset;

	step = (double)tex->height / (double)rc->wall_height;
	pxl.x = rc->x;
	pxl.y = rc->y_tex_start;
	tex_y = 0.0;
	if (pxl.y < 0)
	{
		pxl.y = 0;
		tex_y = abs(rc->y_tex_start) * step;
	}
	while (pxl.y <= rc->y_tex_end && pxl.y < HEIGHT)
	{
		if (tex_y > tex->height)
			tex_y = tex->height - 1;
		offset = round(tex_y) * tex->line_pixels + rc->x_tex;
		pxl.color = tex->buf[offset];
		put_pixel(&game->mlx.img, pxl);
		pxl.y++;
		tex_y += step;
	}
}

void	get_texture(t_game *game, t_raycast *rc, t_img **tex)
{
	if (game->map.arr[rc->map_y][rc->map_x] == DOOR)
	{
		*tex = game->map.D_tex;
	}
	else if (rc->vertical)
	{
		if (rc->ray_dir.x > 0)
			*tex = game->map.EA_tex;
		else
			*tex = game->map.WE_tex;
	}
	else
	{
		if (rc->ray_dir.y > 0)
			*tex = game->map.SO_tex;
		else
			*tex = game->map.NO_tex;
	}
}

void	draw_wall(t_game *game, t_raycast *rc)
{
	t_img	*tex;
	double	wall_x;

	tex = NULL;
	get_texture(game, rc, &tex);
	rc->y_tex_start = -rc->wall_height / 2 + HEIGHT / 2;
	rc->y_tex_end = rc->wall_height / 2 + HEIGHT / 2;
	if (rc->vertical)
		wall_x = rc->pos.y + rc->wall_dist * rc->ray_dir.y;
	else
		wall_x = rc->pos.x + rc->wall_dist * rc->ray_dir.x;
	wall_x -= floor(wall_x);
	rc->x_tex = (int)(wall_x * (double)(tex->width));
	if ((rc->vertical && rc->ray_dir.x < 0) || (!rc->vertical
			&& rc->ray_dir.y > 0))
		rc->x_tex = tex->width - rc->x_tex - 1;
	ver_tex_line(game, rc, tex);
}
