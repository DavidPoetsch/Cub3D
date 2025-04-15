/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:04:19 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/14 15:47:31 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void free_textures(t_game *game)
{
	ft_free_str(&game->map.NO_tex_path);
	ft_free_str(&game->map.EA_tex_path);
	ft_free_str(&game->map.SO_tex_path);
	ft_free_str(&game->map.WE_tex_path);
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
