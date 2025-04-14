/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:59:12 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/11 13:38:05 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		init_game(t_game *game);

int		result_error(const char *msg);
int		result_failed(const char *failed_function, const char *calling_function,
			const char *file_name);
int		result_prog_err(const char *function, const char *file_name);

t_pixel	new_pxl(int x, int y, int color);

int		create_trgb(int t, int r, int g, int b);
int		color_add_alpha(int color, float alpha);

double	get_delta_seconds(void);

#endif // UTILS_H
