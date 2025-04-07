/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:10:06 by dpotsch           #+#    #+#             */
/*   Updated: 2025/03/07 15:18:49 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief ### The isspace function checks for whitespace.
 *
 * ```
 * [' ', '\t', '\n', '\v', '\f', '\r']
 * ```
 *
 * @param c			The character to check.
 * @return int	1 if the character tests true.
 */
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}
