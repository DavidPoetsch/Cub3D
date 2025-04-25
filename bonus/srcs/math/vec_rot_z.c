/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:02:34 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/16 14:00:12 by lstefane         ###   ########.fr       */
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
	return (result);
}
