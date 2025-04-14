/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:04:51 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/11 13:34:31 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

void	free_mlx(t_game *game);
int		init_mlx_stuff(t_game *game);

void	clear_image(t_img *img, int color);
void	put_pixel(t_img *img, t_pixel pxl);
void	put_nbr(t_game *game, t_pixel p, float nbr);
void	put_string(t_game *game, t_pixel p, char *txt);

#endif // MLX_UTILS_H
