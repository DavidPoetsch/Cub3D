/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:56:57 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 12:00:27 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int draw_map(t_game *game)
{
	int i;
	int j;

	j = 0;
	while(game->map.arr[j])
	{
		i = 0;
		while (game->map.arr[j][i])
		{
			if (game->map.arr[j][i] == WALL)
				write_to_buff()
		}
	}

}