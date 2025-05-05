/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:00:36 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/05 09:08:04 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief ## Cub3D
 *
 * A RayCaster with miniLibX
 *
 * `./cub3D map.cub`
 */
int	main(int argc, char *argv[])
{
	t_game	game;
	int		res;

	if (argc != 2)
		return (result_error("invalid argument count"));
	res = SUCCESS;
	ft_bzero(&game, sizeof(t_game));
	res = parse_cub_file(&game, argv[1]);
	/* if (res == SUCCESS)
		res = init_mlx_stuff(&game);
	if (res == SUCCESS)
		res = open_and_assign_textures(&game);
	if (res == SUCCESS)
		res = init_game(&game);
	if (res == SUCCESS)
		res = init_mlx_win(&game);
	if (res == SUCCESS)
	{
		setup_controls(&game);
		mlx_loop_hook(game.mlx.ptr, &render, &game);
		mlx_loop(game.mlx.ptr);
	} */
	free_all(&game);
	return (res);
}
