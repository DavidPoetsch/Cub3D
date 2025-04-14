/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:06:12 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/14 10:49:36 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_space(char c)
{
	return(c == 32 || (c >= 9 && c <= 13));
}

bool	is_letter(char c)
{
	return (c != '\n' && !is_space(c));
}

bool	is_empty_line(char *line)
{
	int i;

	i = 0;
	while(line[i])
	{
		if (is_letter(line[i]))
			return (false);
		i++;
	}
	return (true);
}

