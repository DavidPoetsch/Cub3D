/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:04:51 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/16 14:58:00 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

void	free_mlx(t_game *game);
int		init_mlx_stuff(t_game *game);

void	clear_image(t_img *img, int color);
void	draw_background(t_img *img, t_map *map);

void	draw_line(t_game *game, t_pixel pxl, t_vec dir, double length);
void	draw_area(t_game *game, t_pixel pxl, int size);
void	put_pixel(t_img *img, t_pixel pxl);
void	put_nbr(t_game *game, t_pixel p, float nbr);
void	put_string(t_game *game, t_pixel p, char *txt);

int		open_img(void *mlx, t_img *img, char *path);

#endif // MLX_UTILS_H
