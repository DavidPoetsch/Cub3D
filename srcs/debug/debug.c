/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:44:44 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/18 15:58:00 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_texture_info(t_map *map)
{
	t_textures *curr;
	int i;

	
	curr = map->textures;
	printf("------------------------TEXTURES------------------------\n");
	while(curr)
	{
		i = 0;
		printf("%3s: ", curr->name);
		while(curr->paths[i])
		{
			printf("%s ", curr->paths[i]);
			i++;
		}
		printf("\n");
		curr = curr->next;
	}
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
		printf("%3d.%s", i, curr->line);
		i++;
		curr = curr->next;
	}
	printf("\n--------------------------------------------------------\n");
}

void print_map_arr(char **arr)
{
	int i;

	i = 0;
	printf("--------------------------ARRAY-------------------------\n");
	while(arr[i])
	{
		printf("%3d.%s\n", i, arr[i]);
		i++;
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