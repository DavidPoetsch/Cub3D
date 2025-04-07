/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:14:35 by dpotsch           #+#    #+#             */
/*   Updated: 2025/03/01 12:04:28 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief free a null terminated list of char *.
 * @param array [char*, char*, ...].
 */
void	*ft_free_str_lst(char ***array, bool free_str)
{
	char	**temp;

	if (!array || !*array)
		return (NULL);
	if (free_str)
	{
		temp = *array;
		while (*temp)
		{
			if (*temp != NULL)
				free(*temp);
			*temp = NULL;
			temp++;
		}
	}
	free(*array);
	*array = NULL;
	return (NULL);
}
