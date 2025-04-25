/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:00:53 by dpotsch           #+#    #+#             */
/*   Updated: 2024/09/10 19:39:27 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief	Converts the character c to lowercase.
 * @param c	The character.
 * @return int	Returns the lowercase character.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}
