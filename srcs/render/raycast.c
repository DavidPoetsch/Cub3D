/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:11:19 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/15 10:59:46 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ver_tex_line(t_game *game, int x, int drawStart, int drawEnd, int tex_x, t_texture *tex, int wall_height)
{
	for (int y = drawStart; y <= drawEnd; y++)
	{
		int d = y * 256 - HEIGHT * 128 + wall_height * 128;
		int tex_y = ((d * tex->height) / wall_height) / 256;

		int offset = tex_y * tex->line_length + tex_x * (tex->bpp / 8);
		int color = *(int *)(tex->addr + offset);

		t_pixel pxl = {.x = x, .y = y, .color = color};
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

void calc_wall_dist_and_wall_height(t_raycast *rc)
{
	if (rc->vertical)
		rc->wall_dist = (rc->map_x - rc->pos.x + (1 - rc->step_x) / 2) / rc->ray_dir.x;
	else
		rc->wall_dist = (rc->map_y - rc->pos.y + (1 - rc->step_y) / 2) / rc->ray_dir.y;

	rc->wall_height = (int)(HEIGHT / rc->wall_dist);
}

void draw_wall(t_game *game, t_raycast *rc, int x, t_texture *tex)
{
	int drawStart = -rc->wall_height / 2 + HEIGHT / 2;
	if (drawStart < 0) drawStart = 0;
	int drawEnd = rc->wall_height / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

	// Calculate wall_x
	double wall_x;
	if (rc->vertical)
		wall_x = rc->pos.y + rc->wall_dist * rc->ray_dir.y;
	else
		wall_x = rc->pos.x + rc->wall_dist * rc->ray_dir.x;
	wall_x -= floor(wall_x);

	// Texture x coordinate
	int tex_x = (int)(wall_x * (double)(tex->width));
	if ((rc->vertical && rc->ray_dir.x > 0) || (!rc->vertical && rc->ray_dir.y < 0))
		tex_x = tex->width - tex_x - 1;

	// Draw textured vertical line
	ver_tex_line(game, x, drawStart, drawEnd, tex_x, tex, rc->wall_height);
}

void ray_loop(t_game *game, t_raycast *rc, t_texture *tex)
{
	int x = 0;
	init_raycast(&game->player, rc);
	while (x < WIDTH)
	{
		rc->cam.x = 2 * x / (double) WIDTH - 1;
		rc->ray_dir = vec_add(rc->dir, vec_mul(rc->plane, rc->cam));
		rc->map_x = (int)floor(rc->pos.x);
		rc->map_y = (int)floor(rc->pos.y);
		calc_ray_lengths(rc);
		calc_step_and_init_dist(rc);
		run_dda(game, rc);
		calc_wall_dist_and_wall_height(rc);
		draw_wall(game, rc, x, tex);
		x++;
	}
}

void raycast(t_game *game)
{
	t_raycast rc;
	t_texture tex;

	tex.img = mlx_xpm_file_to_image(game->mlx.ptr, game->map.NO_tex, &tex.width, &tex.height);
	tex.addr = mlx_get_data_addr(tex.img, &tex.bpp, &tex.line_length, &tex.endian);
	ray_loop(game, &rc, &tex);
}
