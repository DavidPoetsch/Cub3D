/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:54:14 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 17:12:11 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int get_path(char *line, char **tex)
{
	*tex = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!*tex)
		return result_failed("ft_strdup", __func__, __FILE__);
	return (SUCCESS);
}

int assign_texture(char *identifier, char **tex, char **split)
{
	if (ft_strncmp(identifier, split[0], 2) == SUCCESS && split[0][2] == '\0')
	{
		if (*tex)
		{
			ft_eprintf("Error: texture (%s) already exists\n", split[0]);
			return (ERROR);
		}
		else
			return get_path(split[1], tex);
	}
	return (ERROR);
}
