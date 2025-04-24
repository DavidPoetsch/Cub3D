/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:31:41 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 14:43:46 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	calc_draw_heigth(t_sprite *sprite)
{
	sprite->draw_start_y = -sprite->size / 2 + HEIGHT / 2 + sprite->offset;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->size / 2 + HEIGHT / 2 + sprite->offset;
	if (sprite->draw_end_y >= HEIGHT)
		sprite->draw_end_y = HEIGHT - 1;
}

static void	calc_draw_width(t_sprite *sprite)
{
	sprite->draw_start_x = -sprite->size / 2 + sprite->screenX;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->size / 2 + sprite->screenX;
	if (sprite->draw_end_x >= WIDTH)
		sprite->draw_end_x = WIDTH - 1;
}

static void	calc_sprite_size(t_sprite *sprite)
{
	sprite->screenX = (int)((WIDTH / 2) * (1 + sprite->camspace.x
				/ sprite->camspace.y));
	sprite->size = abs((int)(HEIGHT / sprite->camspace.y));
	sprite->size /= sprite->size_adjust;
	sprite->offset = sprite->move / sprite->camspace.y;
}

/**
		* @brief This is matrix math to convert from worldspace → screen space.
		transformY: how far away the sprite is (for depth/perspective).
		transformX: where it is horizontally relative to center of screen.
 *
 * @param game
 */
static void	transform_to_camspace(t_player *player, t_sprite *sprite)
{
	double	det;
	double	inv_det;

	sprite->relative.x = sprite->pos.x - player->pos.x;
	sprite->relative.y = sprite->pos.y - player->pos.y;
	det = (player->plane.x * player->rotator.y - player->rotator.x
			* player->plane.y);
	inv_det = 1.0 / det;
	sprite->camspace.x = inv_det * (player->rotator.y * sprite->relative.x
			- player->rotator.x * sprite->relative.y);
	sprite->camspace.y = inv_det * (-player->plane.y * sprite->relative.x
			+ player->plane.x * sprite->relative.y);
}

void	draw_sprites_objects(t_game *game)
{
	int			i;
	t_sprite	*sprite;

	i = 0;
	while (i < game->map.sprite_count)
	{
		sprite = &game->map.sprite[i];
		if (sprite->type == ENEMY)
			update_enemy_pos(game);
		check_collectables(game, sprite);
		transform_to_camspace(&game->player, sprite);
		if (game->map.sprite[i].camspace.y < 0.1 || sprite->hidden
			|| (sprite->type == ENEMY && !game->enemy.alive))
		{
			i++;
			continue ;
		}
		calc_sprite_size(sprite);
		calc_draw_heigth(sprite);
		calc_draw_width(sprite);
		draw_sprite_tex(sprite, game);
		i++;
	}
}
