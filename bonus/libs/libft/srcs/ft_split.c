/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:04:10 by dpotsch           #+#    #+#             */
/*   Updated: 2025/01/28 10:09:45 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	count_words(char const *str, char c);
static char		*create_word(char const *str, size_t count, size_t i);
static size_t	create_list(char **res, char const *str, char c, size_t words);
static char		**return_or_free(char **result, size_t i_res, size_t words);

/**
 * @brief	Allocates (with malloc(3)) and returns an array
 *				of strings obtained by splitting ’s’ using the
 *				character ’c’ as a delimiter. The array must end
 *				with a NULL pointer.
 * @param s	The string to be split.
 * @param c	The delimiter character.
 * @return char**	The array of new strings resulting from
 *								the split. NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	i_res;
	char	**res;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)ft_calloc((words + 1), sizeof(char *));
	if (res == NULL)
		return (NULL);
	i_res = create_list(res, s, c, words);
	return (return_or_free(res, i_res, words));
}

static size_t	count_words(char const *str, char c)
{
	t_split_helper	sh;

	ft_bzero(&sh, sizeof(sh));
	while (str[sh.i] != '\0')
	{
		if (str[sh.i] == '\'')
			sh.in_qts = !sh.in_qts;
		if (str[sh.i] == '\"')
			sh.in_dbl_qts = !sh.in_dbl_qts;
		if (str[sh.i] == c && !sh.in_qts && !sh.in_dbl_qts)
		{
			if (sh.count > 0)
				sh.words++;
			sh.count = 0;
		}
		else
			sh.count++;
		sh.i++;
	}
	if (sh.count > 0)
		sh.words++;
	return (sh.words);
}

/*
	Tested like this:
		static int	test = 0;
		test++;
		if (test == 4)
			return (NULL);
*/
static char	*create_word(char const *str, size_t count, size_t i)
{
	size_t	icopy;
	char	*new_word;

	icopy = 0;
	new_word = (char *)ft_calloc((count + 1), sizeof(char));
	if (new_word == NULL)
		return (NULL);
	while (icopy < count)
	{
		new_word[icopy] = str[icopy + i - count];
		icopy++;
	}
	new_word[icopy] = '\0';
	return (new_word);
}

static size_t	create_list(char **res, char const *str, char c, size_t words)
{
	t_split_helper	sh;

	ft_bzero(&sh, sizeof(sh));
	while (sh.words < words)
	{
		if (str[sh.i] == '\'')
			sh.in_qts = !sh.in_qts;
		if (str[sh.i] == '\"')
			sh.in_dbl_qts = !sh.in_dbl_qts;
		if ((str[sh.i] == c && !sh.in_qts && !sh.in_dbl_qts) || !str[sh.i])
		{
			if (sh.count > 0)
			{
				res[sh.words] = create_word(str, sh.count, sh.i);
				if (res[sh.words] == NULL)
					break ;
				sh.words++;
				sh.count = 0;
			}
		}
		else
			sh.count++;
		sh.i++;
	}
	return (sh.words);
}

/*
	words = 4 i_res = 4 = OK
	words = 4 i_res = 3 = NOK
*/
static char	**return_or_free(char **result, size_t i_res, size_t words)
{
	if (i_res < words)
	{
		if (i_res > 0)
		{
			i_res--;
			while (i_res > 0)
			{
				free(result[i_res]);
				result[i_res] = NULL;
				i_res--;
			}
			free(result[i_res]);
			result[i_res] = NULL;
		}
		free(result);
		result = NULL;
		return (NULL);
	}
	return (result);
}

/* // run with "leaks --atExit -- ./a.out"
#include <stdio.h>

int	main(void)
{
	char	*string;
	char	**result;
	int		i;

	string = "1 2 3 4 5 ";
	result = ft_split(string, ' ');
	if (result != NULL)
	{
		printf("------------------\n");
		i = 0;
		while (result[i] != NULL)
		{
			printf("%s\n", result[i]);
			i++;
		}
		printf("%d, %s\n",i, result[i]);
		printf("------------------\n");
		i = 0;
		while (result[i] != NULL)
		{
			printf("free %d '%s'\n", i, result[i]);
			free(result[i]);
			result[i] = NULL;
			i++;
		}
		printf("free %d 'result'\n", i);
		free(result);
		result = NULL;
		printf("------------------\n");
	}
	else
		printf("result NULL\n");
	return (0);
} */