/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_base_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:53:48 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 16:03:06 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	assign_texture(char *name, t_img **img, t_textures *texs, \
		bool mandatory)
{
	int			len;
	t_textures	*curr;

	curr = texs;
	len = ft_strlen(name);
	while (curr)
	{
		if (ft_strncmp(name, curr->name, len) == 0 && curr->name[len] == '\0')
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
	if (mandatory)
	{
		ft_eprintf("Error: texture missing for %s\n", name);
		return (ERROR);
	}
	return (SUCCESS);
}

int	assign_base_textures(t_map *map)
{
	int	res;

	if (!map->textures)
		return (result_error("texture list missing"));
	res = assign_texture("NO", &map->no_tex, map->textures, 1);
	if (res == SUCCESS)
		res = assign_texture("SO", &map->so_tex, map->textures, 1);
	if (res == SUCCESS)
		res = assign_texture("WE", &map->we_tex, map->textures, 1);
	if (res == SUCCESS)
		res = assign_texture("EA", &map->ea_tex, map->textures, 1);
	return (res);
}
