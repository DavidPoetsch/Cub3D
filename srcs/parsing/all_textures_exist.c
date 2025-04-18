/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_textures_exist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:45:38 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/18 14:25:30 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_texture(char *str, t_textures *textures)
{
	t_textures *curr;
	int len;

	if (!str)
		return (ERROR);
	curr = textures;
	len = ft_strlen(str);
	while(curr)
	{
		if (ft_strncmp(str, curr->name, len) && curr->name[len] == '\0')
			return (SUCCESS);
		curr = curr->next;
	}
	return (ERROR);
}

int check_texture_exists(char c, t_textures *textures)
{
	int res;
	static bool wall_checked;

	if (c == OPEN ||( c == WALL && wall_checked))
		return (SUCCESS);
	if (c == WALL)
	{
		res = check_texture("NO", textures);
		if (res == SUCCESS)
			res = check_texture("SO", textures);
		if (res == SUCCESS)
			res = check_texture("WE", textures);
		if (res == SUCCESS)
			res = check_texture("EA", textures);
		if (res == SUCCESS)
			wall_checked = true;
	}
	else
		res = check_texture(&c, textures);
	return (res);
}

int all_textures_exist(t_map *map)
{
	int res;
	int x;
	int y;
	
	if (!map->textures || !map->arr)
		return (ERROR);
	res = SUCCESS;
	y = 0;
	while(map->arr[y])
	{
		x = 0;
		while(map->arr[y][x])
		{
			res = check_texture_exists(map->arr[y][x], map->textures);
			if (res != SUCCESS)
				break;
			x++;
		}
		y++;
	}
	if (res == SUCCESS)
	{
		printf("%sALL TEXTURES EXIST!%s\n", GREEN_BOLD, RESET);
	}
	else
		printf("%sNOT ALL TEXTURES EXIST!%s\n", RED_BOLD, RESET);
	return (res);
}
