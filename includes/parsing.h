/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:28:31 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 14:04:21 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* ********************************* PARSING ********************************** */
int parse_cub_file(t_game *game, char *file);

//PARSE LST TO ARR
int convert_lst_to_arr(t_map *map);

//PARSE MAP LST
int	parse_map_lst(t_map *map, int fd);
void	clear_map_lst(t_map_lst **map);

//PARSE TEXTURES
int parse_textures(t_map *map, int fd);

//PLAYER START
bool	is_player(char c);
int	check_player_start(t_map *map, t_player *player);

//GET COLORS
int assign_color(char identifier, t_color **color, char **split);

//GET TEXTURES
int assign_texture(char *identifier, char **tex, char **split);


/* ********************************* UTILS ********************************** */

// LINE UTILS
bool	is_space(char c);
bool	is_letter(char c);
bool	is_empty_line(char *line);

// REMOVE WHITE SPACES
char	*remove_white_spaces(char *line);

#endif //PARSING_H