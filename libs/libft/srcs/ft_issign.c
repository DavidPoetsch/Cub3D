/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:00:53 by dpotsch           #+#    #+#             */
/*   Updated: 2024/10/24 14:41:54 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The issign() function tests if a character is '+' or '-'
 * @param c			The character to check.
 * @return int	1 if the character tests true.
 */
int	ft_issign(int c)
{
	return (c == '+' || c == '-');
}
