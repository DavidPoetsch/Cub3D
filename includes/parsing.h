/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:28:31 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/22 08:52:15 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* ********************************* PARSING ********************************** */
int parse_cub_file(t_game *game, char *file);


//ALL TEXTURES EXIST
int all_textures_exist(t_map *map);
int check_texture(char *str, t_textures *textures);

//ASSIGN BASE TEXTURES
int assign_base_textures(t_game *game, t_map *map);

//CHECK ASSIGN COLORS
int check_assign_colors(t_map *map);

//PARSE TEX LST
char	**get_paths(char *name, t_textures *textures);
int		append_to_texlst(t_textures **tex_lst, t_textures *new);
t_textures *create_new_texlst(char **paths);

//PARSE LST TO ARR
int convert_lst_to_arr(t_map *map);

//PARSE MAP LST
int add_to_map_lst(char *line, t_map_lst **map);
int	parse_map_lst(t_map *map, int fd);
void	clear_map_lst(t_map_lst **map);

//PARSE MAP
int parse_map(t_game *game, int fd);

//PARSE SPRITES
int parse_sprites(t_map *map);

//PARSE TEXTURES
int parse_textures(t_map *map, int fd);

//PLAYER START
bool	is_player(char c);
int	check_player_start(t_map *map, t_player *player);

//PARSE DOORS
int safe_doors(t_map *map);

/* ********************************* UTILS ********************************** */

// LINE UTILS
bool	is_space(char c);
bool	is_letter(char c);
bool	is_empty_line(char *line);

// REMOVE WHITE SPACES
char	*remove_white_spaces(char *line);

#endif //PARSING_H