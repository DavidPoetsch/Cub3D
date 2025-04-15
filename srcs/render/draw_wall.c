/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:54:45 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/15 16:07:53 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ver_tex_line(t_game *game, int x, int drawStart, int drawEnd, int tex_x, t_img *tex, int wall_height)
{
	t_pixel pxl;
	double step;
	double tex_pos;
	int	tex_y;
	int offset;
	int color;

	if (!tex)
		return;

	step = 1.0 * tex->height / wall_height;
	tex_pos = (drawStart - HEIGHT / 2 + wall_height / 2) * step;
	while (drawStart <= drawEnd)
	{
		tex_y = (int)tex_pos & (tex->height - 1); // wrap around if needed
		tex_pos += step;
		offset = tex_y * tex->line_pixels + tex_x;
		color = tex->buf[offset];
		pxl = new_pxl(x, drawStart, color);
		put_pixel(&game->mlx.img, pxl);
		drawStart++;
	}
}

void get_texture(t_game *game, t_raycast *rc, t_img **tex)
{
	if (game->map.arr[rc->map_y][rc->map_x] == DOOR)
	{
		*tex = &game->map.D_tex;
	}
	else if (rc->vertical) //WALLS
	{
		if (rc->ray_dir.x > 0) // WEST
			*tex = &game->map.WE_tex;
		else
			*tex = &game->map.EA_tex;
	}
	else
	{
		if (rc->ray_dir.y > 0) // SÜD
			*tex = &game->map.SO_tex;
		else
			*tex = &game->map.NO_tex;
	}
}

void draw_wall(t_game *game, t_raycast *rc, int x)
{
	t_img *tex;
	int drawStart;
	int drawEnd;
	int tex_x;
	double wall_x;

	//assign texture;
	tex = NULL;
	get_texture(game, rc, &tex);

	drawStart = -rc->wall_height / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = rc->wall_height / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;

	// Calculate wall_x
	if (rc->vertical)
		wall_x = rc->pos.y + rc->wall_dist * rc->ray_dir.y;
	else
		wall_x = rc->pos.x + rc->wall_dist * rc->ray_dir.x;
	wall_x -= floor(wall_x);

	// Texture x coordinate or flip texture when looking from the backside
	tex_x = (int)(wall_x * (double)(tex->width));
	if ((rc->vertical && rc->ray_dir.x > 0) || (!rc->vertical && rc->ray_dir.y < 0))
		tex_x = tex->width - tex_x - 1;

	// Draw textured vertical line
	ver_tex_line(game, x, drawStart, drawEnd, tex_x, tex, rc->wall_height);
}