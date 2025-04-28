/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:28:31 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/28 17:08:37 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* ********************************* PARSING ******************************** */
int			parse_cub_file(t_game *game, char *file);

// ASSIGN BASE TEXTURES
int			assign_base_textures(t_map *map);

// CHECK ASSIGN COLORS
int			check_assign_colors(t_map *map);

// CHECK COLOR EXISTS
int			check_colors_exists(t_map *map);

// PARSE FILE EXTENSIONS
int	check_file_extension(char *file, char *extension);

// PARSE TEX LST
char		**get_paths(char *name, t_textures *textures);
int			append_to_texlst(t_textures **tex_lst, t_textures *new);
t_textures	*create_new_texlst(char **paths);

// PARSE TEX LST UTILS
int			get_tex_count(char **paths);

// PARSE LST TO ARR
int			convert_lst_to_arr(t_map *map);

// PARSE MAP LST
int			add_to_map_lst(char *line, t_map_lst **map);
int			parse_map_lst(t_map *map, int fd);
void		clear_map_lst(t_map_lst **map);

// PARSE MAP
int			parse_map(t_game *game, int fd);

// PARSE MAP VALID
int			is_map_valid(t_map *map);

// PARSE OPEN TEXTURES
int			open_textures(t_textures *textures, void *mlx);

// PARSE TEXTURES
int			parse_textures(t_map *map, int fd);

// PARSE TEXTURE VALID
bool		is_valid_texture(char *path);

// PLAYER START
bool		is_player(char c);
int			check_player_start(t_map *map, t_player *player);

/* ********************************* UTILS ********************************** */

// LINE UTILS
bool		is_space(char c);
bool		is_letter(char c);
bool		is_empty_line(char *line);
bool		is_only_digits(char *str);

#endif // PARSING_H