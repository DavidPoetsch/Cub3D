/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:01:53 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 14:42:11 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

void	setup_controls(t_game *game);
void	check_controls(t_game *game);

/* **********************************EVENTS********************************* */

int		destroy_event(t_game *game);
int		key_press_event(int keycode, t_game *game);
int		key_release_event(int keycode, t_game *game);

/* **********************************HOOKS********************************* */

// CONTROLS
void	key_hooks(t_game *game);

#endif // CONTROLS_H
