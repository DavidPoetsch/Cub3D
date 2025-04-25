/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delta_seconds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:05:33 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 14:23:51 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	get_delta_seconds(void)
{
	static struct timeval	last_time;
	struct timeval			current_time;
	double					start_sec;
	double					end_sec;

	gettimeofday(&current_time, NULL);
	if (last_time.tv_sec == 0 && last_time.tv_usec == 0)
	{
		last_time = current_time;
		return (0.0);
	}
	start_sec = last_time.tv_sec + last_time.tv_usec / 1000000.0;
	end_sec = current_time.tv_sec + current_time.tv_usec / 1000000.0;
	last_time = current_time;
	return (end_sec - start_sec);
}
