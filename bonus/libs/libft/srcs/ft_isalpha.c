/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:00:53 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:54:28 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The isalpha() function tests for any character for which
					isupper(3) or islower(3) is true. The value of the argument
					must be representable as an unsigned char
					or the value of EOF.
 * @param c 		The character to check.
 * @return int	1 if the character tests true.
 */
int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
