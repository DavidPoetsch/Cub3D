/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:23:46 by dpotsch           #+#    #+#             */
/*   Updated: 2025/01/30 14:32:22 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../includes/libft.h"

char	*joinbuff(t_file_handler *fh, char *read_buff, int read_res)
{
	char	*new;

	if (fh->size_buff < fh->size_remainder + read_res)
	{
		while (fh->size_buff < fh->size_remainder + read_res)
		{
			if (fh->size_buff > INT_MAX)
			{
				fh->size_buff = fh->size_remainder + read_res;
				break ;
			}
			fh->size_buff = (fh->size_buff) + 1 + (fh->size_buff) * 2;
		}
		new = (char *)ft_calloc(fh->size_buff, sizeof(char));
		if (!new)
			return (NULL);
		fh->new_buff = true;
	}
	else
		new = fh->buff;
	if (fh->buff != NULL && fh->new_buff)
		ft_memcpy(new, fh->buff, fh->size_remainder);
	ft_memcpy(new + fh->size_remainder, read_buff, read_res);
	fh->size_remainder = fh->size_remainder + read_res;
	return (new);
}

/**
 * @brief Split buffer.
 * @param buff Character buffer (not null terminated);
 * @param size_split size of first string.
 * @return char* Returns one null terminated string and the remaining buff.
 */
char	**split_buffer(char *buff, int size_buff, int size_split)
{
	char	**res;
	int		remainder_available;

	res = (char **)ft_calloc(2, sizeof(char *));
	if (!res)
		return (NULL);
	res[0] = (char *)ft_calloc(size_split + 1, sizeof(char));
	remainder_available = size_buff > size_split;
	if (remainder_available)
		res[1] = (char *)ft_calloc((size_buff - size_split), sizeof(char));
	if (!res[0] || (!res[1] && remainder_available))
	{
		free(res[0]);
		free(res[1]);
		free(res);
		res = NULL;
		return (NULL);
	}
	ft_memcpy(res[0], buff, size_split);
	if (remainder_available)
		ft_memcpy(res[1], buff + size_split, size_buff - size_split);
	return (res);
}

char	*free_file_handler(t_list_manager *lm, int fd, bool err_buff)
{
	t_file_handler	*curr_fh;
	t_file_handler	*prev_fh;

	prev_fh = NULL;
	curr_fh = lm->first;
	while (curr_fh)
	{
		if (curr_fh->fd == fd && (curr_fh->eof || curr_fh->error || err_buff))
		{
			if (prev_fh != NULL)
				prev_fh->next = curr_fh->next;
			else
				lm->first = curr_fh->next;
			if (curr_fh->next == NULL)
				lm->last = prev_fh;
			free(curr_fh->buff);
			curr_fh->buff = NULL;
			free(curr_fh);
			curr_fh = NULL;
			break ;
		}
		prev_fh = curr_fh;
		curr_fh = curr_fh->next;
	}
	return (NULL);
}
