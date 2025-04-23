/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:01:29 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 12:04:41 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_pos	set_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

t_pos	copy_pos(t_pos pos)
{
	t_pos	new_pos;

	new_pos.x = pos.x;
	new_pos.y = pos.y;
	return (new_pos);
}
