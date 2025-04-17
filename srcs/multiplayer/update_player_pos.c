/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:32:50 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/17 13:53:41 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	update_player_pos(t_game *game)
{
	int fd;
	char *file;

	file = "./test/player_pos.txt";
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	ft_fprintf(fd, "%d,%d\n", game->player.pos.x, game->player.pos.y);
}

void	read_enemy_pos(t_game *game)
{
	t_vec pos;
	int i;
	int read_bytes;
	char buf[1024];
	int fd;
	char *file;

	file = "./test/enemy_pos.txt";
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	read_bytes = read(fd, buf, 1024);
	i = 0;
	if (read_bytes > 0)
		pos.x = ft_atoi(buf);
	while(i < read_bytes && buf[i] != ',' && buf[i] != '\n')
		i++;
	if (buf[i] && buf[i + 1])
			pos.y = ft_atoi(&buf[i]);
	game->enemy.pos.x = pos.x;
	game->enemy.pos.y = pos.y;
	// ft_printf("pos: %d,%d\n", pos.x, pos.y);
}
