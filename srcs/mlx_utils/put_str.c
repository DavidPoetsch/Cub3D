/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:50:01 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/11 13:33:54 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_string(t_game *game, t_pixel p, char *txt)
{
	if (!game || !game->mlx.ptr || !game->mlx.win)
		return ;
	if (!txt)
		mlx_string_put(game->mlx.ptr, game->mlx.win, p.x, p.y, p.color, "NULL");
	else
	{
		mlx_string_put(game->mlx.ptr, game->mlx.win, p.x, p.y, p.color, txt);
	}
}
