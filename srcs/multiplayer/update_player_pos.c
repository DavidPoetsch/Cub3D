/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:32:50 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/17 16:40:07 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	write_float_2digit(float f, int fd)
{
	int int_part = (int)f;
	int frac_part = (int)((f - int_part) * 100);
	if (frac_part < 0)
		frac_part = -frac_part;
	ft_putnbr_fd(int_part, fd);
	ft_putchar_fd('.', fd);
	if (frac_part < 10)
		ft_putchar_fd('0', fd); // padding for single-digit fractions
	ft_putnbr_fd(frac_part, fd);
}

void	update_player_pos(t_game *game)
{
	int fd;
	char *file;

	file = "./test/player_pos.txt";
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write_float_2digit(game->player.pos.x, fd);
	write(fd, ",", 1);
	write_float_2digit(game->player.pos.y, fd);
	write(fd, "\n", 1);
}

t_vec parse_position(const char *str) {
	t_vec pos;
	pos.x = strtof(str, (char **)&str);
	if (*str == ',') str++;
	pos.y = strtof(str, NULL);
	return pos;
}

void	read_enemy_pos(t_game *game)
{
	t_vec pos;
	int i;
	int read_bytes;
	char buf[100];
	int fd;
	char *file;

	file = "./test/enemy_pos.txt";
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	read_bytes = read(fd, buf, 100);
	i = 0;
	if (read_bytes > 0)
	{
		pos = parse_position(buf);
		game->enemy.pos = vec_set(pos.x, pos.y);
	}
}
