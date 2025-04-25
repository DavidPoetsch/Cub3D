/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_arr_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:46:36 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 13:43:14 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief get the lenght of a null terminated double array.
 * @param array	input double array.
 * @return int lenght of the double array.
 */
int	ft_double_arr_len(void **array)
{
	int	length;

	length = 0;
	if (!array)
		return (0);
	while (array[length] != NULL)
	{
		length++;
	}
	return (length);
}
