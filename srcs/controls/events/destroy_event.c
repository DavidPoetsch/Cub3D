/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:30:47 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 09:24:38 by lstefane         ###   ########.fr       */
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
