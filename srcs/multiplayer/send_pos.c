/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:32:50 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 16:34:16 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	write_float_2digit(float f, int fd)
{
	int	int_part;
	int	frac_part;

	int_part = (int)f;
	frac_part = (int)((f - int_part) * 100);
	if (frac_part < 0)
		frac_part = -frac_part;
	ft_putnbr_fd(int_part, fd);
	ft_putchar_fd('.', fd);
	if (frac_part < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(frac_part, fd);
}

void	send_pos(t_game *game)
{
	int	fd;

	fd = open(F_SND_POS, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write_float_2digit(game->player.pos.x, fd);
	write(fd, ",", 1);
	write_float_2digit(game->player.pos.y, fd);
	write(fd, "\n", 1);
}
