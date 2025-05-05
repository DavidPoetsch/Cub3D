/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_exists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:57:20 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/05 16:02:52 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_commas(char *paths, char *name)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (paths[i])
	{
		if (paths[i] == ',')
			count++;
		i++;
	}
	if (count == 2)
		return (SUCCESS);
	if (count < 2)
		ft_eprintf("Error: color channels missing in color (%s)\n", name);
	if (count > 2)
		ft_eprintf("Error: too many commas in color input (%s)\n", name);
	return (ERROR);
}

static int	check_color(char *name, t_textures *textures)
{
	t_textures	*curr;

	curr = textures;
	while (curr)
	{
		if (ft_strcmp(name, curr->name))
			return (check_commas(curr->paths[0], name));
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
