/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:46:37 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 16:50:08 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int check_file_format(char *file)
{
	char *file_ending;

	file_ending = ft_strrchr(file, '.');
	if (ft_strcmp(file_ending, ".cub"))
		return (SUCCESS);
	ft_eprintf("Error: invalid file format (%s)\n", file_ending);
	return (ERROR);
}

int	parse_cub_file(t_game *game, char *file)
{
	int	fd;
	int	res;

	res = check_file_format(file);
	if (res != SUCCESS)
		return (ERROR);
	fd = open(file, O_RDONLY);
	if (fd == FAILED)
	{
		ft_eprintf("Error: failed to open '%s'\n", file);
		return (ERROR);
	}
	res = parse_textures(&game->map, fd);
	if (res == SUCCESS)
		res = parse_map(game, fd);
	if (res == SUCCESS)
		res = open_textures(game->map.textures, game->mlx.ptr);
	if (res == SUCCESS)
		res = assign_base_textures(&game->map, game);
	if (res == SUCCESS && game->map.door_count > 0)
		res = safe_doors(&game->map);
	if (res == SUCCESS)
		res = parse_sprites(&game->map, game);
	close(fd);
	return (res);
}
