/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:01:53 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/15 14:12:02 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

void	controls(t_game *game);

/* **********************************EVENTS********************************* */

//DESTROY EVENT
int		destroy_event(t_game *game);

//KEY PRESS EVENT
int		key_press_event(int keycode, t_game *game);

//KEY RELEASE EVENT
int		key_release_event(int keycode, t_game *game);

//MOUSE MOVE EVENT
int		mouse_move_event(int x, int y, t_game *game);

/* **********************************HOOKS********************************* */

//CONTROLS
void	key_hooks(t_game *game);
void	mouse_hooks(t_game *game);

#endif
