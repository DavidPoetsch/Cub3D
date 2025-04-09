/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:46:37 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 16:18:45 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int parse_cub_file(t_game *game, char *file)
{
	int fd;
	int res;

	(void) game;
	res = SUCCESS;
	fd = open(file, O_RDONLY);
	if (fd == FAILED)
		return (result_failed("open", __func__, __FILE__));
	res = parse_textures(&game->map, fd);
	if (res == SUCCESS)
		print_texture_info(&game->map);
	if (res == SUCCESS)
		parse_map(game, fd);
	close(fd);
	return (res);
}
