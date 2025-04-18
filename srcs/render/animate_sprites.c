/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:20:24 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/18 12:21:25 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	update_sprite(t_sprite *sprite)
{
	size_t time;
	if (sprite->time == 0)
	{
		sprite->time = get_time_ms();
		sprite->tex = &sprite->texs[0];
		return;
	}
	time = get_time_ms();
	if (time > sprite->time + sprite->update_t)
	{
		sprite->time = time;
		sprite->t_id++;
		if (sprite->t_id == sprite->tex_count)
			sprite->t_id = 0;
		sprite->tex = &sprite->texs[sprite->t_id];
	}
}


void animate_sprites(t_map *map)
{
	int i;

	i = 0;
	while (i < map->sprite_count)
	{
		if (map->sprite[i].tex_count > 1)
		{
			update_sprite(&map->sprite[i]);
		}
		else
			map->sprite[i].tex = &map->sprite[i].texs[0];
		i++;
	}
}