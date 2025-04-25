/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:29:54 by dpotsch           #+#    #+#             */
/*   Updated: 2024/09/09 20:01:07 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief				The isascii() function tests for an ASCII character,
 								which is any character between 0 and octal 0177.
								(ocatal 0177 = 127 decimal)
 * @param c			The character to check.
 * @return int	1 if the character tests true.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
