/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:30:54 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 11:53:36 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void set_sprite_type(char tile, t_sprite *sprite)
{
	sprite->type = tile;
	if (tile == AMMO || tile == HEALTH)
		sprite->is_collectable = true;
}

void set_size_and_move(t_sprite *sprite)
{
	if (sprite->type == ENEMY)
	{
		sprite->size_adjust = 1;
		sprite->move = 100;
	}
	if (sprite->type == TORCH)
	{
		sprite->size_adjust = 2;
		sprite->move = -150;
	}
	if(sprite->type == AMMO || sprite->type == HEALTH)
	{
		sprite->size_adjust = 4;
		sprite->move = 200;
	}
}

void init_enemy(t_game *game, t_sprite *sprite)
{
	game->enemy.sprite = sprite;
	game->enemy.alive = true;
	game->enemy.hit_time = HITMARKER;
	game->enemy.pos.x = game->enemy.sprite->pos.x;
	game->enemy.pos.y = game->enemy.sprite->pos.y;
	game->enemy.pos_start.x = game->enemy.sprite->pos.x;
	game->enemy.pos_start.y = game->enemy.sprite->pos.y;
}

int	assign_tex(t_sprite *sprite, char tile, t_textures *textures)
{
	t_textures *curr;
	static int anim;

	curr = textures;
	while(curr)
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

int get_count(t_map *map, int x, int y)
{
	int count;

	count = 0;
	if (map->arr[y][x] != TORCH)
		return 1;
	else
	{
		if (map->arr[y + 1][x] && map->arr[y + 1][x] == WALL)
			count++;
		if (map->arr[y - 1][x] && map->arr[y - 1][x] == WALL)
			count++;
		if (map->arr[y][x + 1] && map->arr[y][x + 1] == WALL)
			count++;
		if (map->arr[y][x - 1] && map->arr[y][x - 1] == WALL)
			count++;
		return (count);
	}
}

int init_sprite(t_map *map, int x, int y, t_sprite *sprite)
{
	int res;

	sprite->pos.x = x + 0.5;
	sprite->pos.y  = y + 0.5;
	set_sprite_type(map->arr[y][x], sprite);
	set_size_and_move(sprite);
	res = assign_tex(sprite, map->arr[y][x], map->textures);
	return (res);
}

void check_hits(t_wall_hit *hit, int x, int y, char **map)
{
	if (!hit || !map)
		return;
	if (map[y - 1][x] && map[y - 1][x] == WALL)
		hit->n = 1;
	if (map[y + 1][x] && map[y + 1][x] == WALL)
		hit->s = 1;
	if (map[y][x + 1] && map[y][x + 1] == WALL)
		hit->e = 1;
	if (map[y][x - 1] && map[y][x - 1] == WALL)
		hit->w = 1;
}

void change_placement(t_sprite *sprite, t_wall_hit *hit)
{
	if (hit->n)
	{
		sprite->pos.y -= 0.45;
		hit->n = 0;
		return;
	}
	if (hit->e)
	{
		sprite->pos.x += 0.45;
		hit->e = 0;
		return;
	}
	if (hit->s)
	{
		sprite->pos.y += 0.45;
		hit->s = 0;
		return;
	}
	if (hit->w)
	{
		sprite->pos.x -= 0.45;
		hit->w = 0;
		return;
	}
}

void adjust_placement(t_map *map, int count, int x, int y)
{
	t_wall_hit hit;
	int i;

	hit.n = 0;
	hit.w = 0;
	hit.s = 0;
	hit.e = 0;
	i = 1;
	check_hits(&hit, x, y, map->arr);
	while (i <= count)
	{
		change_placement(&map->sprite[map->curr_sprites - i], &hit);
		i++;
	}
}

int sprite_loop(t_map *map, t_game *game, int x, int y)
{
	int i;
	int res;
	int count;

	i = 0;
	res = SUCCESS;
	count = get_count(map, x, y);
	while(i < count && res == SUCCESS)
	{
		res = init_sprite(map, x, y, &map->sprite[map->curr_sprites]);
		if (map->sprite[map->curr_sprites].type == ENEMY)
			init_enemy(game, &map->sprite[map->curr_sprites]);
		map->curr_sprites++;
		i++;;
	}
	if (map->sprite[map->curr_sprites - 1].type == TORCH)
		adjust_placement(map, count, x, y);
	return (res);
}

int get_sprites(t_map *map, t_game *game)
{
	int x;
	int y;
	int res;

	y = 0;
	res = SUCCESS;
	while(map->arr[y] && res == SUCCESS)
	{
		x = 0;
		while(map->arr[y][x] && res == SUCCESS)
		{
			if (is_sprite(map->arr[y][x]))
				res = sprite_loop(map, game, x, y);
			x++;
		}
		y++;
	}
	return (res);
}

int parse_sprites(t_map *map, t_game *game)
{
	int res;

	res = SUCCESS;
	map->sprite_count = get_sprite_count(map);
	map->curr_sprites = 0;
	if (map->sprite_count > 0)
	{
		map->sprite = ft_calloc(map->sprite_count, sizeof(t_sprite));
		if (!map->sprite)
			return (ERROR);
		res = get_sprites(map, game);
		//print_sprite_info(map);
	}
	return (res);
}
