/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_extensions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:17:39 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/28 16:20:26 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int get_ext_index(char *file, char c)
{
	int	i;

	i =  ft_strlen(file) - 1;
	while(file[i] && i >= 0)
	{
		if (file[i] == c)
			return (i);
		i--;
	}
	return (0);
}

int check_file_extension(char *file, char *extension)
{
	int i;

	if (!file || !extension)
		return (result_prog_err(__func__,__FILE__));
	i = get_ext_index(file, '.');
	if (i == 0 || file[i - 1] == '/')
	{
		ft_eprintf("Error: invalid file (%s) expected (%s - file)\n", file, extension);
		return (ERROR);
	}
	if (!ft_strcmp(file + i, extension))
	{
		ft_eprintf("Error: wrong file format (%s)\n", file);
		return (ERROR);
	}
	return (SUCCESS);
}
