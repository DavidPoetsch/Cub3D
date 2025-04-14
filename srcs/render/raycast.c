/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:11:19 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/11 11:55:24 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ver_line(t_game *game, int x, int drawStart, int drawEnd, int color)
{
	t_pixel pxl;

	if (drawStart > drawEnd) // swap if needed
	{
			int temp = drawStart;
			drawStart = drawEnd;
			drawEnd = temp;
	}

	for (int y = drawStart; y <= drawEnd; y++)
	{
		pxl.x =x;
		pxl.y = y;
		pxl.color = color;
		put_pixel(&game->mlx.img, pxl);
	}
}

void	init_raycast(t_game *game, t_raycast *rc)
{
	rc->pos.x = game->player.cam.pos.x;
	rc->pos.y = game->player.cam.pos.y;

	rc->dir.x = game->player.cam.rotator.x;
	rc->dir.y = game->player.cam.rotator.y;
	rc->plane.x = game->render.plane.x;
	rc->plane.y = game->render.plane.y;
}

void	calc_ray_lengths(t_raycast *rc)
{
	double raydir_x_square;
	double raydir_y_square;

	raydir_x_square = rc->ray_dir.x * rc->ray_dir.x;
	raydir_y_square = rc->ray_dir.y * rc->ray_dir.y;
	if (rc->ray_dir.x == 0)
		rc->ray_delta.x = 1e30;
	else
		rc->ray_delta.x = sqrt(1 + (raydir_y_square) / (raydir_x_square));
	if (rc->ray_dir.y == 0)
		rc->ray_delta.y = 1e30;
	else
		rc->ray_delta.y = sqrt(1 + (raydir_x_square) / (raydir_y_square));
}

void	calc_step_and_init_dist(t_raycast *rc)
{
	if (rc->ray_dir.x < 0)
	{
		rc->step_x = -1;
		rc->ray_dist.x = (rc->pos.x - rc->map_x) * rc->ray_delta.x;
	}
	else
	{
		rc->step_x = 1;
		rc->ray_dist.x = (rc->map_x + 1.0 - rc->pos.x) * rc->ray_delta.x;
	}
	if (rc->ray_dir.y < 0)
	{
		rc->step_y = -1;
		rc->ray_dist.y = (rc->pos.y - rc->map_y) * rc->ray_delta.y;
	}
	else
	{
		rc->step_y = 1;
		rc->ray_dist.y = (rc->map_y + 1.0 - rc->pos.y) * rc->ray_delta.y;
	}
}

bool	is_collision(char **map, int x, int y)
{
	if (map[x][y] == WALL)
		return (true);
	return (false);
}

void	run_dda(t_game *game, t_raycast *rc)
{
	bool collision;

	collision = false;
	while (!collision)
	{
		if (rc->ray_dist.x < rc->ray_dist.y)
		{
			rc->ray_dist.x += rc->ray_delta.x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->ray_dist.y += rc->ray_delta.y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		collision = is_collision(game->map.arr, rc->map_x, rc->map_y);
	}
}

void	calc_wall_dist_and_wall_height(t_raycast *rc)
{
	if (rc->side == 0)
	{
		rc->wall_dist = (rc->ray_dist.x - rc->ray_delta.x);
	}
	else
	{
		rc->wall_dist = (rc->ray_dist.y - rc->ray_delta.y);
	}
	rc->wall_height = (int)(HEIGHT / rc->wall_dist);
}

void	draw_wall(t_game *game, t_raycast *rc, int x)
{
	int drawStart = -rc->wall_height / 2 + HEIGHT / 2;
	if(drawStart < 0)
		drawStart = 0;
	int drawEnd = rc->wall_height / 2 + HEIGHT / 2;
	if(drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;

	//choose wall color
	int color = create_trgb(1, 255, 0, 0);
	if (rc->side == 1) {
		color = create_trgb(1, 0, 255, 0);
	}
	ver_line(game, x, drawStart, drawEnd, color);
}

void	ray_loop(t_game *game, t_raycast *rc)
{
	int x;

	x = 0;
	init_raycast(game, rc);
	while (x < WIDTH)
	{
		rc->cam.x = 2 * x / (double) WIDTH - 1;
		rc->cam.y = rc->cam.x;
		rc->ray_dir = vec_add(rc->dir, vec_mul(rc->plane, rc->cam));
		rc->map_x = (int)floor(rc->pos.x);
		rc->map_y = (int)floor(rc->pos.y);
		calc_ray_lengths(rc);
		calc_step_and_init_dist(rc);
		run_dda(game, rc);
		calc_wall_dist_and_wall_height(rc);
		draw_wall(game, rc, x);
		x++;
	}
}

void	raycast(t_game *game)
{
	t_raycast rc;

	init_raycast(game, &rc);
	ray_loop(game, &rc);
}
