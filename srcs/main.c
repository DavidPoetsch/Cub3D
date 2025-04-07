/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:00:36 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/07 15:23:38 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	render_next_frame(t_game *game)
{
	(void)game;
	return (SUCCESS);
}

int main(int argc, char *argv[])
{
	t_game game;

	(void)argc;
	(void)argv;
	game.mlx.ptr = mlx_init();
	game.mlx.win = mlx_new_window(game.mlx.ptr, WIDTH, HEIGHT, "Hello world!");
	mlx_loop_hook(game.mlx.ptr, &render_next_frame, &game);
	mlx_loop(game.mlx.ptr);
	return 0;
}