/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:01:53 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/07 17:07:00 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

void	controls(t_game *game);

// events

int		destroy_event(t_game *game);
int		key_press_event(int keycode, t_game *game);
int		key_release_event(int keycode, t_game *game);
int		mouse_move_event(t_game *game);

// hooks

void	key_hooks(t_game *game);
void	mouse_hooks(t_game *game);

#endif
