/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_tex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:53:24 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 15:09:36 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_vert_stripe(t_sprite *sprite, t_game *game, int x, int tex_x)
{
	int		d;
	int		y;
	int		tex_y;
	t_pixel	pxl;

	y = sprite->draw_start_y;
	while (y < sprite->draw_end_y)
	{
		d = (y - sprite->offset) * 256 - HEIGHT * 128 + sprite->size * 128;
		tex_y = ((d * sprite->tex->height) / sprite->size) / 256;
		if (tex_x >= 0 && tex_x < sprite->tex->width && tex_y >= 0 && \
			tex_y < sprite->tex->height)
		{
			pxl.x = x;
			pxl.y = y;
			pxl.color = sprite->tex->buf[sprite->tex->width * tex_y + tex_x];
			if ((pxl.color & 0x00FFFFFF) != 0)
				put_pixel(&game->mlx.img, pxl);
		}
		y++;
	}
}

void	draw_sprite_tex(t_sprite *sprite, t_game *game)
{
	int	x;
	int	tex_x;

	x = sprite->draw_start_x;
	while (x < sprite->draw_end_x)
	{
		tex_x = (int)(256 * (x - (-sprite->size / 2 + sprite->screen_x)) \
				* sprite->tex->width / sprite->size) / 256;
		if (sprite->camspace.y > 0 && x > 0 && x < WIDTH
			&& sprite->camspace.y < game->dist_buff[x])
			draw_vert_stripe(sprite, game, x, tex_x);
		x++;
	}
}
