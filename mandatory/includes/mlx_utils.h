/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:04:51 by dpotsch           #+#    #+#             */
/*   Updated: 2025/05/05 12:12:41 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

void	free_mlx(t_game *game);
int		init_mlx_stuff(t_game *game);
int		init_new_img(void *mlx, t_img *img, int width, int height);

void	draw_background(t_img *img, t_map *map);
void	draw_line(t_img *img, t_pixel start, t_vec dir, double length);
void	draw_area(t_img *img, t_pixel pxl, int size);
void	put_pixel(t_img *img, t_pixel pxl);
void	put_nbr(t_game *game, t_pixel p, float nbr);
void	put_string(t_game *game, t_pixel p, char *txt);

int		open_img(void *mlx, t_img *img, char *path);

#endif // MLX_UTILS_H
