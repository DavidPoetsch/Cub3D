/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:52:45 by dpotsch           #+#    #+#             */
/*   Updated: 2025/05/05 12:18:01 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_mlx_ptr(t_game *game)
{
	if (!game)
		return (result_prog_err(__func__, __FILE__));
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		return (result_error("failed to initialize mlx"));
	return (SUCCESS);
}

static int	init_mlx_win(t_game *game)
{
	if (!game)
		return (result_prog_err(__func__, __FILE__));
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIDTH, HEIGHT, WIN_NAME);
	if (!game->mlx.win)
		return (result_error("failed to create new window"));
	return (SUCCESS);
}

static int	open_imgs(t_textures **curr, void *mlx)
{
	int	i;
	int	res;

	i = 0;
	res = SUCCESS;
	while (i < (*curr)->tex_count && res == SUCCESS)
	{
		if (check_file_extension((*curr)->paths[i], ".xpm") != SUCCESS)
			return (ERROR);
		res = open_img(mlx, &(*curr)->imgs[i], (*curr)->paths[i]);
		if (res == ERROR)
			return (ERROR);
		i++;
	}
	return (res);
}

static int	open_textures(t_textures *textures, void *mlx)
{
	t_textures	*curr;
	int			res;

	res = SUCCESS;
	if (!textures)
		return (result_error("no textures parsed"));
	curr = textures;
	while (curr && res == SUCCESS)
	{
		if (is_color(curr))
		{
			curr = curr->next;
			continue ;
		}
		res = open_imgs(&curr, mlx);
		curr = curr->next;
	}
	return (res);
}

int	init_mlx_stuff(t_game *game)
{
	int	res;

	res = init_mlx_ptr(game);
	if (res == SUCCESS)
		res = init_new_img(game->mlx.ptr, &game->mlx.img, WIDTH, HEIGHT);
	if (res == SUCCESS)
		res = open_textures(game->map.textures, game->mlx.ptr);
	if (res == SUCCESS)
		res = init_mlx_win(game);
	return (res);
}
