/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:49:43 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/11 13:34:36 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_nbr(t_game *game, t_pixel p, float nbr)
{
	char	*str_nbr;

	if (!game || !game->mlx.ptr || !game->mlx.win)
		return ;
	str_nbr = ft_itoa(nbr);
	if (str_nbr == NULL)
		put_string(game, p, "NULL");
	else
	{
		put_string(game, p, str_nbr);
		free(str_nbr);
		str_nbr = NULL;
	}
}
