/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:33:41 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/30 10:57:55 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_map_element(char c)
{
	if (c == WALL)
		return (true);
	if (c == OPEN)
		return (true);
	if (is_player(c))
		return (true);
	return (false);
}

int	is_map_line(char *line)
{
	int		x;
	int		y;
	char	**split;

	y = 0;
	split = ft_split(line, ' ');
	if (!split)
		return (result_failed("ft_split", __func__, __FILE__));
	while (split[y])
	{
		x = 0;
		while (split[y][x] && split[y][x] != '\n')
		{
			if (!is_map_element(split[y][x]))
			{
				ft_free_str_lst(&split, true);
				return (ERROR);
			}
			x++;
		}
		y++;
	}
	ft_free_str_lst(&split, true);
	return (SUCCESS);
}
