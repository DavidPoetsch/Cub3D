/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_white_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:18:31 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/08 09:23:40 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int	count_words(char const *str, char c)
{
	int	i;
	int	wordcount;
	int	is_new_word;

	i = 0;
	wordcount = 1;
	is_new_word = 1;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
		{
			is_new_word = 1;
		}
		else if (is_new_word)
		{
			wordcount++;
			is_new_word = 0;
		}
		i++;
	}
	return (wordcount);
}

static int	count_letters(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*remove_white_spaces_inbetween(char *str)
{
	char	*new;
	int		words;
	int		letters;
	int		i;
	int		j;

	words = count_words(str, ' ');
	letters = count_letters(str, ' ');
	new = ft_calloc(letters + words + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i == 0 || str[i] != ' ' || str[i - 1] != ' ')
			new[j++] = str[i];
		i++;
	}
	return (new);
}

char	*remove_white_spaces(char *str)
{
	char	*value;

	if (is_only_space(str))
	{
		free(str);
		return (ft_strdup(" "));
	}
	value = remove_white_spaces_inbetween(str);
	free(str);
	if (!value)
		return (NULL);
	return (value);
}