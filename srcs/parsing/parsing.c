/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:46:37 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 14:05:46 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parse_cub_file(t_game *game, char *file)
{
	int	fd;
	int	res;

	fd = open(file, O_RDONLY);
	if (fd == FAILED)
		return (result_failed("open", __func__, __FILE__));
	res = parse_textures(&game->map, fd);
	if (res == SUCCESS)
		res = parse_map(game, fd);
	if (res == SUCCESS)
		res = open_textures(game->map.textures, game->mlx.ptr);
	if (res == SUCCESS)
		res = assign_base_textures(&game->map);
	if (res == SUCCESS && game->map.door_count > 0)
		res = safe_doors(&game->map);
	if (res == SUCCESS)
		res = parse_sprites(&game->map, game);
	close(fd);
	return (res);
}
