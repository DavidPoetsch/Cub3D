/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:04:19 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 16:08:16 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_all(t_game *game)
{
	free_mlx(game);
	if (game->map.lst)
		clear_map_lst(&game->map.lst);
	if (game->map.arr)
		ft_free_str_lst(&game->map.arr, true);
}

void	free_all_exit(t_game *game)
{
	free_all(game);
	exit(EXIT_FAILURE);
}
