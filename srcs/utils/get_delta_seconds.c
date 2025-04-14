/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delta_seconds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:05:33 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/09 09:08:32 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	get_delta_seconds(void)
{
	static struct timeval	lastTime;
	struct timeval			currentTime;
	double					start_sec;
	double					end_sec;

	gettimeofday(&currentTime, NULL);
	if (lastTime.tv_sec == 0 && lastTime.tv_usec == 0)
	{
		lastTime = currentTime;
		return (0.0);
	}
	start_sec = lastTime.tv_sec + lastTime.tv_usec / 1000000.0;
	end_sec = currentTime.tv_sec + currentTime.tv_usec / 1000000.0;
	lastTime = currentTime;
	return (end_sec - start_sec);
}
