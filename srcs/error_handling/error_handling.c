/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:04:19 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/14 10:24:08 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void free_textures(t_game *game)
{
	if (game->map.NO_tex)
		free(game->map.NO_tex);
	if (game->map.SO_tex)
		free(game->map.SO_tex);
	if (game->map.WE_tex)
		free(game->map.WE_tex);
	if (game->map.EA_tex)
		free(game->map.EA_tex);
}

void	free_all(t_game *game)
{
	free_mlx(game);
	free_textures(game);
	if (game->map.lst)
		clear_map_lst(&game->map.lst);
	if (game->map.arr)
		ft_free_str_lst(&game->map.arr, true);
	if (game->map.floor)
		free(game->map.floor);
	if (game->map.ceiling)
		free(game->map.ceiling);
}

void	free_all_exit(t_game *game)
{
	free_all(game);
	exit(EXIT_FAILURE);
}
