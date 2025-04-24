/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:06:12 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 14:14:58 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

bool	is_letter(char c)
{
	return (c != '\n' && !is_space(c));
}

bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_letter(line[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_only_digits(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (str[i] != '\n' && !ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
