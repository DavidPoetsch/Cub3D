/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:44:44 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 16:23:46 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_texture_info(t_map *map)
{
	t_textures	*curr;
	int			i;

	curr = map->textures;
	printf("------------------------TEXTURES------------------------\n");
	while (curr)
	{
		i = 0;
		printf("%3s: ", curr->name);
		while (curr->paths[i])
		{
			printf("%s ", curr->paths[i]);
			i++;
		}
		printf("Count: %d\n", curr->tex_count);
		if (curr->imgs)
			printf("   IMG: %d\n", curr->imgs->height);
		curr = curr->next;
	}
	printf("--------------------------------------------------------\n");
}

void	print_color_info(t_map *map)
{
	printf("--------------------------COLORS------------------------\n");
	printf("F:\n");
	printf("  C: %d\n", map->floor->col);
	printf("  R:%d\n", map->floor->r);
	printf("  G:%d\n", map->floor->g);
	printf("  B:%d\n", map->floor->b);
	printf("C:\n");
	printf("  C: %d\n", map->ceiling->col);
	printf("  R:%d\n", map->ceiling->r);
	printf("  G:%d\n", map->ceiling->g);
	printf("  B:%d\n", map->ceiling->b);
	printf("--------------------------------------------------------\n");
}

void	print_sprite_info(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->sprite_count)
	{
		j = 0;
		printf("%d.SPRITE\n", i);
		printf("   Type: %d\n", map->sprite[i].type);
		printf("   Tex: %d\n", map->sprite[i].tex_count);
		if (map->sprite[i].is_anim)
		{
			while (j < map->sprite[i].tex_count)
			{
				printf("   Tex: %p\n", &map->sprite[i].tex[j]);
				j++;
			}
		}
		else
			printf("   Tex: %p\n", map->sprite[i].tex);
		printf("   X: %f\n", map->sprite[i].pos.x);
		printf("   Y: %f\n", map->sprite[i].pos.y);
		printf("   Size: %d\n", map->sprite[i].size_adjust);
		i++;
	}
}

void	print_enemy_sprite_info(t_game *game)
{
	int	i;

	if (!game->enemy.sprite)
		return ;
	i = 0;
	printf("%d.ENEMY\n", i);
	printf("   Type: %d\n", game->enemy.sprite->type);
	printf("   Tex: %p\n", game->enemy.sprite->tex);
	printf("   X: %f\n", game->enemy.sprite->pos.x);
	printf("   Y: %f\n", game->enemy.sprite->pos.y);
	printf("   Alive: %d\n", game->enemy.alive);
	printf("   Hidden: %d\n", game->enemy.sprite->hidden);
}
