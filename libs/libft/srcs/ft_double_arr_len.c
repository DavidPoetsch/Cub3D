/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_arr_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:46:36 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:40:56 by dpotsch          ###   ########.fr       */
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
