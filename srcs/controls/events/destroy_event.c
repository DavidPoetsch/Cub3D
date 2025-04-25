/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:30:47 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 11:18:47 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	destroy_event(t_game *game)
{
	if (!game)
		exit (EXIT_FAILURE);
	free_all(game);
	exit(EXIT_SUCCESS);
}
