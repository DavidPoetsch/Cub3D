/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:59:12 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/09 09:17:37 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int	init_game(t_game *game);

int	result_error(const char *msg);
int	result_failed(const char *failed_function, const char *calling_function,
		const char *file_name);
int	result_prog_err(const char *function, const char *file_name);

#endif // UTILS_H
