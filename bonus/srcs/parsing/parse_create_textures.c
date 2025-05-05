/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_create_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:35 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/05 12:06:24 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_color(t_textures *curr)
{
	int	len;

	len = ft_strlen(curr->name);
	if (ft_strncmp("F", curr->name, len) == CMP_OK)
		return (true);
	if (ft_strncmp("C", curr->name, len) == CMP_OK)
		return (true);
	return (false);
}

static int	create_textures(t_textures *textures)
{
	t_textures	*curr;

	if (!textures)
		return (result_error("no textures parsed"));
	curr = textures;
	while (curr)
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
		curr = curr->next;
	}
	return (SUCCESS);
}

int	create_and_assign_textures(t_game *game)
{
	int	res;

	res = SUCCESS;
	if (res == SUCCESS)
		res = create_textures(game->map.textures);
	if (res == SUCCESS)
		res = assign_base_textures(&game->map, game);
	return (res);
}
