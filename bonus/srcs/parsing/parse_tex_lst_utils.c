/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_lst_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:08:18 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/30 12:04:39 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tex(t_textures **tex)
{
	if ((*tex)->name)
		free((*tex)->name);
	if ((*tex)->paths)
		ft_free_str_lst(&(*tex)->paths, true);
	if (*tex)
		free(*tex);
	*tex = NULL;
}

int	get_tex_count(char **paths)
{
	int	i;

	i = 0;
	while (paths && paths[i])
		i++;
	return (i);
}
