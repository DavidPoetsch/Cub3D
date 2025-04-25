/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:59:56 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 14:43:52 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# define M_PI 3.14159265358979323846

t_vec	vec_set(double x, double y);

t_vec	vec_add(t_vec v1, t_vec v2);
t_vec	vec_mul(t_vec v1, t_vec v2);
t_vec	vec_sub(t_vec v1, t_vec v2);
t_vec	vec_rot_z(t_vec v, float angle);

double	square(double num);

#endif // MATH_UTILS_H
