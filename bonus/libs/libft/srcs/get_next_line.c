/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:21:40 by dpotsch           #+#    #+#             */
/*   Updated: 2025/02/24 12:03:24 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*evaluate_buffer(t_file_handler *fh);
int				extend_buffer(t_file_handler *fh, char *read_buff);
int				get_size_nl(t_file_handler *fh);
t_file_handler	*get_file_handler(t_list_manager *lm, int fd, int gnl_cmd);

/**
 * @brief Repeated calls (e.g., using a loop) to this function should let
 *        you read the text file pointed to by the file descriptor,
 *        one line at a time.
 *        The returned line should include the terminating \n character,
 *        except if the end of file was reached.
 *        and does not end with a \n character.
 *        (-D BUFFER_SIZE=n) can define the buffer size for read().
 * @param fd The file descriptor to read from.
 * @return char* Read line: correct behavior.
 *               NULL ifthere is nothing else to read, or an error occurred.
 */
char	*get_next_line(int fd, int gnl_cmd)
{
	static t_list_manager	lm;
	t_file_handler			*fh;
	char					*line;
	char					*read_buff;
	int						read_res;

	gnl_free_buffers(&lm, fd, gnl_cmd);
	fh = get_file_handler(&lm, fd, gnl_cmd);
	if (!fh)
		return (NULL);
	read_buff = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!read_buff)
		return (free_file_handler(&lm, fd, true));
	read_res = -2;
	fh->index_nl = 0;
	while (read_res >= 0 || read_res == -2)
	{
		line = evaluate_buffer(fh);
		if (line != NULL || fh->eof || fh->error)
			break ;
		read_res = extend_buffer(fh, read_buff);
	}
	free(read_buff);
	free_file_handler(&lm, fd, false);
	return (line);
}

/**
 * @brief Check for newline, if found remove the line
 *				from the buff and return it.
 */
char	*evaluate_buffer(t_file_handler *fh)
{
	char	*line;
	int		size_line;
	char	**res;

	line = NULL;
	if (fh->error > NO_GNL_ERROR)
		return (line);
	size_line = get_size_nl(fh);
	if (size_line < 0)
		return (line);
	res = split_buffer(fh->buff, fh->size_remainder, size_line);
	if (!res)
	{
		fh->error = ERR_GNL_MALLOC;
		return (line);
	}
	line = res[0];
	free(fh->buff);
	fh->buff = res[1];
	(fh->size_remainder) -= size_line;
	fh->size_buff = fh->size_remainder;
	free(res);
	return (line);
}

int	extend_buffer(t_file_handler *fh, char *read_buff)
{
	int		read_res;
	char	*new_buff;

	read_res = read(fh->fd, read_buff, BUFFER_SIZE);
	if (read_res > 0)
	{
		new_buff = joinbuff(fh, read_buff, read_res);
		if (!new_buff)
		{
			fh->error = ERR_GNL_MALLOC;
			return (-1);
		}
		if (fh->new_buff)
		{
			free(fh->buff);
			fh->new_buff = false;
		}
		fh->buff = new_buff;
	}
	if (read_res == 0)
		fh->eof = true;
	if (read_res < 0)
		fh->error = ERR_GNL_READ;
	return (read_res);
}

/**
 * @return int	Get size of line if newline was found
 *              or end of file is reached.
 */
int	get_size_nl(t_file_handler *fh)
{
	if (fh->eof && fh->size_remainder > 0)
		return (fh->size_remainder);
	if (!fh->buff || fh->eof)
		return (-1);
	while (fh->index_nl < fh->size_remainder)
	{
		if (fh->buff[fh->index_nl] == '\n')
			return (fh->index_nl + 1);
		(fh->index_nl)++;
	}
	return (-1);
}

t_file_handler	*get_file_handler(t_list_manager *lm, int fd, int gnl_cmd)
{
	t_file_handler	*curent_fh;
	t_file_handler	*new_fh;

	if (fd < 0 || gnl_cmd == GNL_FREE || gnl_cmd == GNL_FREE_ALL)
		return (NULL);
	curent_fh = lm->first;
	while (curent_fh)
	{
		if (curent_fh->fd == fd)
			return (curent_fh);
		curent_fh = curent_fh->next;
	}
	new_fh = (t_file_handler *)ft_calloc(1, sizeof(t_file_handler));
	if (!new_fh)
		return (NULL);
	new_fh->fd = fd;
	if (lm->first == NULL)
	{
		lm->first = new_fh;
		lm->last = new_fh;
		return (new_fh);
	}
	lm->last->next = new_fh;
	lm->last = lm->last->next;
	return (lm->last);
}

/* #include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("testfile.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break;
		free(line);
		i++;
	}
	close(fd);
	return (0);
} */

// #include <fcntl.h>
// #include <stdio.h>
// #include <unistd.h>

// //! TEST DIALOG
// int	main(void)
// {
// 	char *line;
// 	printf("------------------------------------------\n");
// 	printf("get next line \n");
// 	int fd1 = open("file1", O_RDONLY);
// 	int fd2 = open("file2", O_RDONLY);
// 	int fd3 = open("file3", O_RDONLY);

// 	line = get_next_line(fd1, GNL);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd2, GNL);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd3, GNL);
// 	printf("%s", line);
// 	free(line);
// }
