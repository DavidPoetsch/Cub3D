/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:58:54 by dpotsch           #+#    #+#             */
/*   Updated: 2025/03/06 17:41:05 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Free a string and set pointer to null.
 */
void	ft_free_str(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}
