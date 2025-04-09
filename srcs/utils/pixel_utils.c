/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:51:06 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/14 10:36:32 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_pixel new_pxl(int x, int y, int color)
{
	t_pixel pxl;

	pxl.x = x;
	pxl.y = y;
	pxl.color = color;
	return (pxl);
}
