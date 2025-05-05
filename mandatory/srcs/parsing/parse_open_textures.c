/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_open_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:35 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/05 10:07:45 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	open_imgs(t_textures **curr, void *mlx)
{
	int	i;
	int	res;

	i = 0;
	res = SUCCESS;
	while (i < (*curr)->tex_count && res == SUCCESS)
	{
		if (check_file_extension((*curr)->paths[i], ".xpm") != SUCCESS)
			return (ERROR);
		res = open_img(mlx, &(*curr)->imgs[i], (*curr)->paths[i]);
		if (res == ERROR)
			return (ERROR);
		i++;
	}
	return (res);
}

static bool	is_color(t_textures *curr)
{
	int	len;

	len = ft_strlen(curr->name);
	if (ft_strncmp("F", curr->name, len) == CMP_OK)
		return (true);
	if (ft_strncmp("C", curr->name, len) == CMP_OK)
		return (true);
	return (false);
}

static int	open_textures(t_textures *textures, void *mlx)
{
	t_textures	*curr;
	int			res;

	res = SUCCESS;
	if (!textures)
		return (result_error("no textures parsed"));
	curr = textures;
	while (curr && res == SUCCESS)
	{
		if (is_color(curr))
		{
			curr = curr->next;
			continue ;
		}
		curr->tex_count = ft_double_arr_len((void **)curr->paths);
		curr->imgs = ft_calloc(curr->tex_count + 1, sizeof(t_img));
		if (!curr->imgs)
			return (result_failed("ft_calloc", __func__, __FILE__));
		res = open_imgs(&curr, mlx);
		curr = curr->next;
	}
	return (res);
}

int open_and_assign_textures(t_game *game)
{
	int res;

	res = SUCCESS;
	if (res == SUCCESS)
		res = open_textures(game->map.textures, game->mlx.ptr);
	if (res == SUCCESS)
		res = assign_base_textures(&game->map);
	return (res);
}
