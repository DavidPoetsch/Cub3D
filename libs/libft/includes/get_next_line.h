/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:21:47 by dpotsch           #+#    #+#             */
/*   Updated: 2025/01/30 14:59:01 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

enum							e_gnl_command
{
	GNL,
	GNL_FREE,
	GNL_FREE_ALL,
};

enum							e_error_codes_gnl
{
	NO_GNL_ERROR,
	ERR_GNL_MALLOC,
	ERR_GNL_READ
};

// Holds the buffer for each line
typedef struct s_file_handler	t_file_handler;
struct							s_file_handler
{
	int				fd;
	char			*buff;
	size_t			size_buff;
	size_t			size_remainder;
	size_t			index_nl;
	bool			eof;
	bool			new_buff;
	int				error;
	t_file_handler	*next;
};

typedef struct s_list_manager	t_list_manager;
struct						s_list_manager
{
	t_file_handler	*first;
	t_file_handler	*last;
};

char	*get_next_line(int fd, int gnl_cmd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*joinbuff(t_file_handler *fh, char *read_buff, int read_res);
char	**split_buffer(char *buff, int size_buff, int size_split);
char	*free_file_handler(t_list_manager *lm, int fd, bool err_buff);
void	gnl_free_buffers(t_list_manager *lm, int fd, int gnl_cmd);
#endif