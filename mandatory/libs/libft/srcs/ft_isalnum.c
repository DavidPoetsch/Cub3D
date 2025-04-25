/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:22:13 by dpotsch           #+#    #+#             */
/*   Updated: 2025/02/20 14:55:17 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	The isalnum() function tests for any character for which
					isalpha(3) or isdigit(3) is true.
					The value of the argument must be representable 
					as an unsigned char or the value of EOF.
 * @param c	The character to check.
 * @return int	1 if the character tests true.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
