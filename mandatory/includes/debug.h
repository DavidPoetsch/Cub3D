/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:48:30 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 15:01:20 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

void	print_texture_info(t_map *map);
void	print_map_lst(t_map_lst *map);
void	print_map_arr(char **arr);
void	print_color_info(t_map *map);
void	print_sprite_info(t_map *map);
void	print_enemy_sprite_info(t_game *game);

#endif //DEBUG_H