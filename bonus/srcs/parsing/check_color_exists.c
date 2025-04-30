/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_exists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:57:20 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/30 10:51:37 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_color(char *name, t_textures *textures)
{
	t_textures	*curr;

	curr = textures;
	while (curr)
	{
		if (ft_strcmp(name, curr->name))
			return (SUCCESS);
		curr = curr->next;
	}
	ft_eprintf("Error: color (%s) is missing\n", name);
	return (ERROR);
}

int	check_colors_exists(t_map *map)
{
	int	res;

	res = check_color("F", map->textures);
	if (res == SUCCESS)
		res = check_color("C", map->textures);
	return (res);
}
