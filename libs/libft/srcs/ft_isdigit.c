/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:00:53 by dpotsch           #+#    #+#             */
/*   Updated: 2024/09/09 19:54:56 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The isdigit() function tests for a decimal digit character.
					The value of the argument must be representable as an
					unsigned char or the value of EOF.
 * @param c			The character to check.
 * @return int	1 if the character tests true.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
