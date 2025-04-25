/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:30:42 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:40:51 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief The function erases the data in the n bytes
					of the memory starting at the location pointed to by s,
					by writing zeros (bytes containing '\0') to that area.
 * @param s	Startpoint of the memory
 * @param n	amount of bytes to erase
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
