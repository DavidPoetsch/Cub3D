/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:14:35 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/23 13:53:25 by lstefane         ###   ########.fr       */
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
