/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_msg_hide.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:06:03 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 17:14:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	hide_sprite(t_game *game, int x, int y)
{
	int			i;
	t_sprite	*sprites;

	i = 0;
	sprites = game->map.sprite;
	while (i < game->map.sprite_count)
	{
		if (floor(sprites[i].pos.x) == x && floor(sprites[i].pos.y) == y)
		{
			if (sprites[i].type == AMMO)
			{
				sprites[i].hide_time = AMMO_HIDE_TIME;
				sprites[i].hidden = true;
			}
			else if (sprites[i].type == HEALTH)
			{
				sprites[i].hide_time = HEALTH_HIDE_TIME;
				sprites[i].hidden = true;
			}
			return ;
		}
		i++;
	}
}

void	msg_hide_collectable(t_game *game, char buf[MSG_SIZE])
{
	int		x;
	int		y;
	char	*str;

	str = ft_strchr(buf, '[');
	if (!str || (str + 1) == NULL)
		return ;
	str++;
	y = ft_atoi(str);
	str = ft_strchr(buf, ',');
	if (!str || (str + 1) == NULL)
		return ;
	str++;
	x = ft_atoi(str);
	if (x > 0 && x < game->map.width && y > 0 && y < game->map.height)
	{
		hide_sprite(game, x, y);
	}
}
