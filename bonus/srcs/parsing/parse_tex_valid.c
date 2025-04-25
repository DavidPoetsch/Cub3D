/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:33:58 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 14:17:06 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_mand_texture(char *path)
{
	if (ft_strcmp(path, "F"))
		return (true);
	if (ft_strcmp(path, "C"))
		return (true);
	if (ft_strcmp(path, "NO"))
		return (true);
	if (ft_strcmp(path, "SO"))
		return (true);
	if (ft_strcmp(path, "EA"))
		return (true);
	if (ft_strcmp(path, "WE"))
		return (true);
	return (false);
}

static bool	is_sprite_texture(char *path)
{
	if (ft_strcmp(path, "B_D"))
		return (true);
	if (ft_strcmp(path, "B_X"))
		return (true);
	if (ft_strcmp(path, "B_A"))
		return (true);
	if (ft_strcmp(path, "B_T"))
		return (true);
	if (ft_strcmp(path, "B_H"))
		return (true);
	return (false);
}

static bool	is_screen_texture(char *path)
{
	if (ft_strcmp(path, "B_IMG_WIN"))
		return (true);
	if (ft_strcmp(path, "B_IMG_LOSE"))
		return (true);
	if (ft_strcmp(path, "B_IMG_PISTOL"))
		return (true);
	if (ft_strcmp(path, "B_IMG_SHOT"))
		return (true);
	return (false);
}

bool	is_valid_texture(char *path)
{
	bool	valid;

	valid = is_mand_texture(path);
	if (!valid)
		valid = is_sprite_texture(path);
	if (!valid)
		valid = is_screen_texture(path);
	return (valid);
}
