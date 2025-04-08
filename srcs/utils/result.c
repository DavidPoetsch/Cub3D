/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:12:23 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/08 09:10:41 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	result_error(const char *msg)
{
	ft_eprintf("Error: %s\n", msg);
	return (ERROR);
}

int	result_failed(const char *failed_function, const char *calling_function,
		const char *file_name)
{
	ft_eprintf("Error: %s failed in %s (%s).\n", failed_function,
		calling_function, file_name);
	return (ERROR);
}

int	result_prog_err(const char *function, const char *file_name)
{
	ft_eprintf("Error: programming error in %s (%s).\n", function,
		file_name);
	return (ERROR);
}
