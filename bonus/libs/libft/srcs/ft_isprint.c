/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:31:13 by dpotsch           #+#    #+#             */
/*   Updated: 2024/09/10 16:50:12 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief				The isprint() function tests for any printing character,
								including space (‘ ’). The value of the
								argumentmust be representable as an unsigned char
								or the value of EOF.
 * @param c			The character to check.
 * @return int	1 if the character tests true.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
