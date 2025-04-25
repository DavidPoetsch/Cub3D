/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_img_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:59:37 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 12:36:58 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	valid_xy(t_img *img, int x, int y)
{
	return (x >= 0 && y >= 0 && x < img->width && y < img->height);
}

static int	copy_data_no_black(t_img *img1, t_img *img2, t_pixel pxl1,
		t_pixel pxl2)
{
	int	index1;
	int	index2;

	if (!valid_xy(img1, pxl1.x, pxl1.y) || !valid_xy(img2, pxl2.x, pxl2.y))
		return (ERROR);
	index1 = (pxl1.y * img1->line_pixels) + pxl1.x;
	index2 = (pxl2.y * img2->line_pixels) + pxl2.x;
	if ((img1->buf[index1] & 0x00FFFFFF) != 0)
		img2->buf[index2] = img1->buf[index1];
	return (SUCCESS);
}

static int	copy_data(t_img *img1, t_img *img2, t_pixel pxl1, t_pixel pxl2)
{
	int	index1;
	int	index2;

	if (!valid_xy(img1, pxl1.x, pxl1.y) || !valid_xy(img2, pxl2.x, pxl2.y))
		return (ERROR);
	index1 = (pxl1.y * img1->line_pixels) + pxl1.x;
	index2 = (pxl2.y * img2->line_pixels) + pxl2.x;
	img2->buf[index2] = img1->buf[index1];
	return (SUCCESS);
}

/**
 * @brief ### Move content of img1 in img2
 */
void	move_img_buf(t_img *img1, t_img *img2, t_pos pos, bool copy_black)
{
	t_pixel	pxl1;
	t_pixel	pxl2;

	if (!img1 || !img2 || !img1->ptr || !img2->ptr)
		return ;
	pxl1.x = 0;
	pxl2.x = pos.x;
	while (pxl1.x < img1->width)
	{
		pxl1.y = 0;
		pxl2.y = pos.y;
		while (pxl1.y < img1->height)
		{
			if (copy_black && copy_data(img1, img2, pxl1, pxl2) == ERROR)
				break ;
			if (!copy_black && copy_data_no_black(img1, img2, pxl1,
					pxl2) == ERROR)
				break ;
			pxl1.y++;
			pxl2.y++;
		}
		pxl1.x++;
		pxl2.x++;
	}
}
