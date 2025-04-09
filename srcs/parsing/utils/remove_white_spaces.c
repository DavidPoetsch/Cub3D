/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_white_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:18:31 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/08 11:18:48 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	count_letters(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_letter(str[i]))
			count++;
		i++;
	}
	return (count);
}

static void	copy_letters(char *line, char **str)
{
	int i;
	int j;
	bool inbetween;

	i = 0;
	j = 0;
	inbetween = true;
	while (line[j])
	{
		if ((i != 0 && line[j] == ' ' && inbetween))
		{
			(*str)[i++] = line[j];
			inbetween = false;
		}
		else if (is_letter(line[j]))
		{
			(*str)[i++] = line[j];
		}
		j++;
	}
}

char	*remove_white_spaces(char *line)
{
	char *str;
	int count;

	count = count_letters(line) + 1;
	str = calloc(count, sizeof(char)); //ft_calloc
	if (!str)
	{
		//free(line);
		return NULL;
	}
	copy_letters(line, &str);
	//free(line);
	return (str);
}
