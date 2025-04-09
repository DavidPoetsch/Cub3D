/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:00:36 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/14 10:41:48 by dpotsch          ###   ########.fr       */
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
	int	res;
	t_game	game; //! consider allocate this, stack has limited size

	if (argc != 2)
		return (result_error("invalid argument count"));
	res = SUCCESS;
	ft_bzero(&game, sizeof(t_game));
	res = parse_cub_file(&game, argv[1]);
	if (res == SUCCESS)
		res = init_mlx_stuff(&game);
	if (res == SUCCESS)
	{
		init_game(&game);
		controls(&game);
		mlx_loop_hook(game.mlx.ptr, &render, &game);
		mlx_loop(game.mlx.ptr);
	}
	free_mlx(&game);
	return (res);
}
