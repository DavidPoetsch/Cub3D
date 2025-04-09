/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:44:44 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 12:42:21 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_texture_info(t_map *map)
{
	printf("------------------------TEXTURES------------------------\n");
	printf("NO: %s\n", map->NO_tex);
	printf("SO: %s\n", map->SO_tex);
	printf("WE: %s\n", map->WE_tex);
	printf("EA: %s\n", map->EA_tex);
	printf("F:\n");
	printf("  R:%d\n", map->floor->r);
	printf("  G:%d\n", map->floor->g);
	printf("  B:%d\n", map->floor->b);
	printf("C:\n");
	printf("  R:%d\n", map->ceiling->r);
	printf("  G:%d\n", map->ceiling->g);
	printf("  B:%d\n", map->ceiling->b);
	printf("--------------------------------------------------------\n");
}

void print_map_lst(t_map_lst *map)
{
	t_map_lst *curr;
	int	i;

	i = 0;
	curr = map;
	printf("--------------------------LIST--------------------------\n");
	while(curr)
	{
		printf("%d.%s", i, curr->line);
		i++;
		curr = curr->next;
	}
	printf("--------------------------------------------------------\n");
}

void print_map_arr(char **arr)
{
	int i;

	i = 0;
	printf("--------------------------ARRAY-------------------------\n");
	while(arr[i])
	{
		printf("%d.%s\n", i, arr[i]);
		i++;
	}
	printf("--------------------------------------------------------\n");

}