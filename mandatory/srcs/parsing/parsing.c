/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:46:37 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/05 12:05:22 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parse_cub_file(t_game *game, char *file)
{
	int	fd;
	int	res;

	res = check_file_extension(file, ".cub");
	if (res != SUCCESS)
		return (ERROR);
	fd = open(file, O_RDONLY);
	if (fd == FAILED)
	{
		ft_eprintf("Error: failed to open %s\n", file);
		return (ERROR);
	}
	res = parse_textures(&game->map, fd);
	if (res == SUCCESS)
		res = parse_map(game, fd);
	if (res == SUCCESS)
		res = create_and_assign_textures(game);
	close(fd);
	return (res);
}
