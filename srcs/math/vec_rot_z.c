/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:02:34 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/08 16:17:24 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_vec	vec_rot_z(t_vec v, float angle)
{
	t_vec	result;
	float	rad;

	rad = angle * (M_PI / 180.0);
	result.x = v.x * cos(rad) - v.y * sin(rad);
	result.y = v.x * sin(rad) + v.y * cos(rad);
	result.z = v.z;
	return (result);
}
