/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_base_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:53:48 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 11:58:18 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	assign_texture(char *name, t_img **img, t_textures *textures)
{
	int			len;
	t_textures	*curr;

	if (!name || !textures)
		return (ERROR);
	curr = textures;
	len = ft_strlen(name);
	while (curr)
	{
		if (ft_strncmp(name, curr->name, len) == CMP_OK \
			&& curr->name[len] == '\0')
		{
			if (curr->tex_count != 1)
			{
				ft_eprintf("Error: too many texture arguments for %s\n", name);
				return (ERROR);
			}
			*img = &curr->imgs[0];
			return (SUCCESS);
		}
		curr = curr->next;
	}
	ft_eprintf("Error: texture missing for %s\n", name);
	return (ERROR);
}

static int	assign_screen_textures(t_game *game, t_textures *textures)
{
	int	res;

	res = assign_texture("IMG_WIN", &game->img_victory, textures);
	if (res == SUCCESS)
		res = assign_texture("IMG_LOSE", &game->img_lose, textures);
	if (res == SUCCESS)
		res = assign_texture("IMG_PISTOL", &game->img_pistol, textures);
	if (res == SUCCESS)
		res = assign_texture("IMG_SHOT", &game->img_shot, textures);
	return (res);
}

int	assign_base_textures(t_map *map, t_game *game)
{
	int	res;

	res = assign_texture("NO", &map->no_tex, map->textures);
	if (res == SUCCESS)
		res = assign_texture("SO", &map->so_tex, map->textures);
	if (res == SUCCESS)
		res = assign_texture("WE", &map->we_tex, map->textures);
	if (res == SUCCESS)
		res = assign_texture("EA", &map->ea_tex, map->textures);
	if (res == SUCCESS && map->door_count > 0)
		res = assign_texture("D", &map->d_tex, map->textures);
	if (res == SUCCESS)
		res = assign_screen_textures(game, game->map.textures);
	return (res);
}
