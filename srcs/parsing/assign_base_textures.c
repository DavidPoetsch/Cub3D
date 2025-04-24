/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_base_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:53:48 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 13:56:05 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	assign_base_texture(char *name, t_img **img, t_textures *textures)
{
	int			len;
	t_textures	*curr;

	if (!name || !textures)
		return (ERROR);
	curr = textures;
	len = ft_strlen(name);
	while (curr)
	{
		if (ft_strncmp(name, curr->name, len) == CMP_OK
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

int	assign_base_textures(t_map *map)

{
	int	res;

	res = assign_base_texture("NO", &map->NO_tex, map->textures);
	if (res == SUCCESS)
		res = assign_base_texture("SO", &map->SO_tex, map->textures);
	if (res == SUCCESS)
		res = assign_base_texture("WE", &map->WE_tex, map->textures);
	if (res == SUCCESS)
		res = assign_base_texture("EA", &map->EA_tex, map->textures);
	if (res == SUCCESS && map->door_count > 0)
		res = assign_base_texture("D", &map->D_tex, map->textures);
	return (res);
}
