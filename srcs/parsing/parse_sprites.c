/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:30:54 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/23 11:41:36 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_sprite_size(char tile)
{
	if (tile == AMMO || tile == TORCH)
		return 2;
	return 1;
}

void set_sprite_type(char tile, t_sprite *sprite)
{
	sprite->type = tile;
	if (tile == AMMO)
		sprite->is_collectable = true;
}

void set_sprite_pos(t_map *map, int x, int y, t_sprite *sprite)
{
	if(map->arr[y][x] != TORCH)
	{
		sprite->pos.x = x + 0.5;
		sprite->pos.y  = y + 0.5;
	}
	else
	{
		sprite->pos.x = x + 0.05;
		sprite->pos.y = y + 0.05;
	}
}

void set_size_and_move(t_sprite *sprite)
{
	sprite->size_adjust = 1;
	if (sprite->type == AMMO || sprite->type == TORCH)
		sprite->size_adjust = 2;
	if (sprite->type == TORCH)
		sprite->move = -500;
	if (sprite->type == ENEMY)
		sprite->move = 50;
	if(sprite->type == AMMO)
		sprite->move = 200;
}

void init_enemy(t_game *game, t_sprite *sprite)
{
	game->enemy.sprite = sprite;
	game->enemy.health = 100;
	game->enemy.alive = true;
}

int	assign_tex(t_sprite *sprite, char tile, t_textures *textures)
{
	t_textures *curr;

	curr = textures;
	while(curr)
	{
		if (ft_strncmp(&tile, curr->name, 1) == CMP_OK && curr->name[1] == '\0')
		{
			sprite->tex_count = curr->tex_count;
			if (sprite->tex_count > 1)
				sprite->is_anim = true;
			sprite->tex = &curr->imgs[0];
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
			count +=1;
		if (map->arr[y - 1][x] && map->arr[y - 1][x] == WALL)
			count +=1;
		if (map->arr[y][x + 1] && map->arr[y][x + 1] == WALL)
			count +=1;
		if (map->arr[y][x - 1] && map->arr[y][x - 1] == WALL)
			count +=1;
		return (count);
	}
}

int init_sprite(t_map *map, int x, int y, t_sprite *sprite)
{
	int res;

	set_sprite_pos(map, x, y, sprite);
	set_sprite_type(map->arr[y][x], sprite);
	set_size_and_move(sprite);
	res = assign_tex(sprite, map->arr[y][x], map->textures);
	return (res);
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
	printf("SPRITE COUNT: %d\n", map->sprite_count);
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
