/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:51:03 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/16 12:59:19 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// 1: While raycasting the walls, store the perpendicular distance of each vertical stripe in a 1D ZBuffer
// 2: Calculate the distance of each sprite to the player
// 3: Use this distance to sort the sprites, from furthest away to closest to the camera
// 4: Project the sprite on the camera plane (in 2D): subtract the player position from the sprite position, then multiply the result with the inverse of the 2x2 camera matrix
// 5: Calculate the size of the sprite on the screen (both in x and y direction) by using the perpendicular distance
// 6: Draw the sprites vertical stripe by vertical stripe, don't draw the vertical stripe if the distance is further away than the 1D ZBuffer of the walls of the current stripe
// 7: Draw the vertical stripe pixel by pixel, make sure there's an invisible color or all sprites would be rectangles

/* 		//SPRITE CASTING
	//sort sprites from far to close
	for(int i = 0; i < game->map.sprite_count; i++)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((posX - sprite[i].x) * (posX - sprite[i].x) + (posY - sprite[i].y) * (posY - sprite[i].y)); //sqrt not taken, unneeded
	}
	sortSprites(spriteOrder, spriteDistance, numSprites);
 */
	//after sorting the sprites, do the projection and draw them

void draw_sprites(t_game *game)
{
	//SORT FIRST
	for(int i = 0; i < game->map.sprite_count; i++)
	{
		
		if (game->map.sprite[i].hidden)
			continue;;
		double spriteDistance = (game->player.pos.x - game->map.sprite[i].x) * (game->player.pos.x - game->map.sprite[i].x) + (game->player.pos.y - game->map.sprite[i].y) + (game->player.pos.y - game->map.sprite[i].y);
		if (spriteDistance <= 1.5)
			game->map.sprite[i].hidden = true;
			//translate sprite position to relative to camera
		
		double spriteX = game->map.sprite[i].x - game->player.pos.x; //sprite X relative to player
		double spriteY = game->map.sprite[i].y - game->player.pos.y; //sprite Y relative to player
		double invDet = 1.0 / (game->player.plane.x * game->player.rotator.y - game->player.rotator.x * game->player.plane.y);
		double transformX = invDet * (game->player.rotator.y * spriteX - game->player.rotator.x * spriteY);
		double transformY = invDet * (-game->player.plane.y * spriteX + game->player.plane.x * spriteY);
		int spriteScreenX = (int)((WIDTH / 2) * (1 + transformX / transformY));

		//calculate height of the sprite on screen
		int spriteHeight = abs((int)(HEIGHT / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + HEIGHT / 2;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + HEIGHT / 2;
		if(drawEndY >= HEIGHT) drawEndY = HEIGHT - 1;

		//calculate width of the sprite
		int spriteWidth = abs((int)(HEIGHT / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= WIDTH) drawEndX = WIDTH - 1;
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * 128 / spriteWidth) / 256;
			if(transformY > 0 && stripe > 0 && stripe < WIDTH && transformY < game->dist_buff[stripe])
			{
				t_pixel pxl;
				for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
				{
					int d = (y) * 256 - HEIGHT * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
					int texY = ((d * 128) / spriteHeight) / 256;
					pxl.y = y;
					pxl.x = stripe;
					pxl.color = game->map.sprite[i].tex.buf[128 * texY + texX];
					if((pxl.color & 0x00FFFFFF) != 0)
						put_pixel(&game->mlx.img, pxl);//paint pixel if it isn't black, black is the invisible color
				}
			}
		}
	}
}
