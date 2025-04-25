/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:33:58 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 16:12:52 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_valid_texture(char *path)
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
