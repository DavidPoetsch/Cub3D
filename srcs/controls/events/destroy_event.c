/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:30:47 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/07 16:55:48 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	destroy_event(t_game *game)
{
	if (!game)
		exit (EXIT_FAILURE);
	free_mlx(game);
	exit(EXIT_SUCCESS);
}
