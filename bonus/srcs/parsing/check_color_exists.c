/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_exists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:57:20 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 14:28:38 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_color(char *name, t_textures *textures)
{
	t_textures	*curr;
	int			len;

	curr = textures;
	len = ft_strlen(name);
	while (curr)
	{
		if (ft_strncmp(name, curr->name, len) == CMP_OK
			&& curr->name[len] == '\0')
			return (SUCCESS);
		curr = curr->next;
	}
	return (result_error("color missing"));
}

int	check_colors_exists(t_map *map)
{
	int	res;

	res = check_color("F", map->textures);
	if (res == SUCCESS)
		res = check_color("C", map->textures);
	return (res);
}
