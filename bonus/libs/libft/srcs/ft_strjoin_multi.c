/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:50:02 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Joins all strings from the two dimensional 'strings' array.
 * @param strings	The array with strings. The last element should be NULL.
 * @return char*	Combined string.
 */
char	*ft_strjoin_multi(char **strings)
{
	size_t	i;
	char	*result;
	char	*temp;

	i = 0;
	result = NULL;
	temp = NULL;
	while (strings && strings[i])
	{
		if (i == 0)
			result = ft_strdup(strings[i]);
		else
		{
			temp = result;
			if (temp)
			{
				result = ft_strjoin(temp, strings[i]);
				free(temp);
			}
			if (!result)
				return (NULL);
		}
		i++;
	}
	return (result);
}

/* #include <stdio.h>
int	main(void)
{
	// Test Case 1: Joining multiple strings
	char *test1[] = {"Hello, ", "this ", "is ", "a ", "test.", NULL};
	char *result1 = ft_strjoin_multi(test1);
	printf("Test 1: %s\n", result1);
	free(result1);

	// Test Case 2: Joining single string
	char *test2[] = {"SingleString", NULL};
	char *result2 = ft_strjoin_multi(test2);
	printf("Test 2: %s\n", result2);
	free(result2);

	// Test Case 3: Empty array
	char *test3[] = {NULL};
	char *result3 = ft_strjoin_multi(test3);
	printf("Test 3: %s\n", result3 ? result3 : "(null)");
	free(result3);

	// Test Case 4: Strings with empty strings in between
	char *test4[] = {"Hello", "", "World", "", "!", NULL};
	char *result4 = ft_strjoin_multi(test4);
	printf("Test 4: %s\n", result4);
	free(result4);

	// Test Case 5: NULL input
	char **test5 = NULL;
	char *result5 = ft_strjoin_multi(test5);
	printf("Test 5: %s\n", result5 ? result5 : "(null)");
	free(result5);

	return (0);
} */
