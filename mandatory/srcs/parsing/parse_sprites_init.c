/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:10:23 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 14:14:48 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	assign_tex(t_sprite *sprite, char tile, t_textures *textures)
{
	t_textures	*curr;
	static int	anim;

	curr = textures;
	while (curr)
	{
		if (ft_strncmp(&tile, curr->name, 1) == CMP_OK && curr->name[1] == '\0')
		{
			sprite->tex_count = curr->tex_count;
			if (sprite->tex_count > 1)
			{
				anim++;
				sprite->is_anim = true;
				sprite->update_t = ANIM_TIME;
				sprite->anim_offset = anim % sprite->tex_count - 1;
			}
			sprite->texs = &curr->imgs[0];
			sprite->tex = &sprite->texs[0];
			return (SUCCESS);
		}
		curr = curr->next;
	}
	ft_eprintf("Error: texture missing for %c\n", tile);
	return (ERROR);
}

static void	set_size_and_move(t_sprite *sprite)
{
	if (sprite->type == ENEMY)
	{
		sprite->size_adjust = 1;
		sprite->move = 150;
	}
	if (sprite->type == TORCH)
	{
		sprite->size_adjust = 2;
		sprite->move = -150;
	}
	if (sprite->type == AMMO || sprite->type == HEALTH)
	{
		sprite->size_adjust = 4;
		sprite->move = 200;
	}
}

static void	set_sprite_type(char tile, t_sprite *sprite)
{
	sprite->type = tile;
	if (tile == AMMO || tile == HEALTH)
		sprite->is_collectable = true;
}

void	init_enemy(t_game *game, t_sprite *sprite)
{
	game->enemy.sprite = sprite;
	game->enemy.alive = true;
	game->enemy.hit_time = HITMARKER;
	game->enemy.pos.x = game->enemy.sprite->pos.x;
	game->enemy.pos.y = game->enemy.sprite->pos.y;
	game->enemy.pos_start.x = game->enemy.sprite->pos.x;
	game->enemy.pos_start.y = game->enemy.sprite->pos.y;
}

int	init_sprite(t_map *map, int x, int y, t_sprite *sprite)
{
	int	res;

	sprite->pos.x = x + 0.5;
	sprite->pos.y = y + 0.5;
	set_sprite_type(map->arr[y][x], sprite);
	set_size_and_move(sprite);
	res = assign_tex(sprite, map->arr[y][x], map->textures);
	return (res);
}
