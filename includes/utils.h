/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:59:12 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/17 15:36:37 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//COLOR UTILS
int		create_trgb(int t, int r, int g, int b);
int		color_add_alpha(int color, float alpha);

//GET DELTA SECONDS
double	get_delta_seconds(void);

//INIT GAME
int		init_game(t_game *game);

//MAP UTILS
bool	is_collision(char **map, int x, int y);
bool	is_enemy(char **map, int x, int y);
bool	is_door(char **map, int x, int y);
bool	is_player(char c);
bool is_valid_map_char(char c);

//PIXEL UTILS
t_pixel	new_pxl(int x, int y, int color);

//RESULT
int		result_error(const char *msg);
int		result_failed(const char *failed_function, const char *calling_function,
			const char *file_name);
int		result_prog_err(const char *function, const char *file_name);

#endif // UTILS_H
