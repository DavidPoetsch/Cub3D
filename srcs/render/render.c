/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:46:56 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/14 10:38:05 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void verLine(t_game *game, int x, int drawStart, int drawEnd, int color)
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

void	raycast_old(t_game *game)
{
	// t_raycast *rc;
	int w = WIDTH;
	int h = HEIGHT;

	char **worldMap;

	worldMap = game->map.arr;

	double posX = game->player.cam.pos.x;
	double posY = game->player.cam.pos.y;

	double dirX = -1.0, dirY = 0.0; //initial direction vector
	double planeX = 0.0, planeY = 0.66; //the 2d raycaster version of camera plane

	for(int x = 0; x < w; x++)
	{
		//calculate ray position and direction
		double cameraX = 2*x/(double)w-1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		//which box of the map we're in
		int mapX = (int)posX;
		int mapY = (int)posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] == WALL) hit = WALL;
		}

		//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h) drawEnd = h - 1;

		//choose wall color
		int color;
		switch(worldMap[mapX][mapY])
		{
			case WALL:  color = create_trgb(1, 255, 0, 0);  break; //red
			case 2:  color = create_trgb(1, 0, 255, 0);  break; //green
			case 3:  color = create_trgb(1, 0, 0, 255);   break; //blue
			case 4:  color = create_trgb(1, 255, 255, 255);  break; //white
			default: color = create_trgb(1, 128, 128, 128); break;
		}

		//give x and y sides different brightness
		if (side == 1) {
			color_add_alpha(color, 0.5);
		}

		//draw the pixels of the stripe as a vertical line
		verLine(game, x, drawStart, drawEnd, color);
	}
}

int render(t_game *game)
{
	clear_image(&game->mlx.img, create_trgb(1,200,200,200));
	raycast(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img.ptr, 0, 0);
	game->render.delta_seconds = get_delta_seconds();
	draw_fps(game);
	usleep(16666);
	// printf("Frames %f\n", 1.0 / game->render.delta_seconds);
	return (SUCCESS); 
}
