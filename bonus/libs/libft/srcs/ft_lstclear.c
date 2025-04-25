/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:37:14 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Deletes and frees the given node and every
					successor of that node, using the function ’del’
					and	free(3).
					Finally, the pointer to the list must be set to
					NULL.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used
							to delete the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*cur;

	if (*lst == NULL)
		return ;
	next = *lst;
	while (next)
	{
		cur = next;
		next = cur->next;
		ft_lstdelone(cur, del);
	}
	*lst = NULL;
}
