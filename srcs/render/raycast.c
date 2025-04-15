/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:11:19 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/15 10:55:42 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ver_line(t_game *game, int x, int drawStart, int drawEnd, int color)
{
	t_pixel pxl;

	for (int y = drawStart; y <= drawEnd; y++)
	{
		pxl.x =x;
		pxl.y = y;
		pxl.color = color;
		put_pixel(&game->mlx.img, pxl);
	}
}

void	init_raycast(t_player *player, t_raycast *rc)
{
	rc->pos.x = player->pos.x;
	rc->pos.y = player->pos.y;

	rc->dir.x = player->rotator.x;
	rc->dir.y = player->rotator.y;
	rc->plane.x = player->plane.x;
	rc->plane.y = player->plane.y;
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
	if (map[y][x] == WALL)
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
			rc->vertical = 1;
		}
		else
		{
			rc->ray_dist.y += rc->ray_delta.y;
			rc->map_y += rc->step_y;
			rc->vertical = 0;
		}
		collision = is_collision(game->map.arr, rc->map_x, rc->map_y);
	}
}

void	calc_wall_dist_and_wall_height(t_raycast *rc)
{
	if (rc->vertical)
		rc->wall_dist = (rc->map_x - rc->pos.x + (1 - rc->step_x) / 2) / rc->ray_dir.x;
	else
		rc->wall_dist = (rc->map_y - rc->pos.y + (1 - rc->step_y) / 2) / rc->ray_dir.y;


	rc->wall_height = (int)(HEIGHT / rc->wall_dist);
}

void	draw_wall(t_game *game, t_raycast *rc, int x)
{
	int color;
	int drawStart;
	int drawEnd;

	drawStart = -rc->wall_height / 2 + HEIGHT / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = rc->wall_height / 2 + HEIGHT / 2;
	if(drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	if (rc->vertical)
	{
		if (rc->ray_dir.x > 0) // WEST
			color = create_trgb(1, 0, 255, 0); //WEST
		else
			color = create_trgb(1, 128, 128, 255); //OST
	}
	else
	{
		if (rc->ray_dir.y > 0) // SÜD
			color = create_trgb(1, 255, 0, 0); //SÜD
		else
			color = create_trgb(1, 0, 0, 255); //NORD
	}
	ver_line(game, x, drawStart, drawEnd, color);
}

void	ray_loop(t_game *game, t_raycast *rc)
{
	int x;

	x = 0;
	init_raycast(&game->player, rc);
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

	init_raycast(&game->player, &rc);
	ray_loop(game, &rc);
}
