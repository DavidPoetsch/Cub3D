/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:01:53 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 15:27:03 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

void	setup_controls(t_game *game);
void	check_controls(t_game *game);

/* **********************************EVENTS********************************* */

//DESTROY EVENT
int		destroy_event(t_game *game);

//KEY PRESS EVENT
int		key_press_event(int keycode, t_game *game);

//KEY RELEASE EVENT
int		key_release_event(int keycode, t_game *game);

//MOUSE MOVE EVENT
int		mouse_move_event(int x, int y, t_game *game);

//MOUSE PRESS
int mouse_press_event(int button, int x, int y, t_game *game);

//MOUSE RELASE
int mouse_release_event(int button, int x, int y, t_game *game);

/* **********************************HOOKS********************************* */

//CONTROLS
void	key_hooks(t_game *game);
void	mouse_hooks(t_game *game);

#endif
