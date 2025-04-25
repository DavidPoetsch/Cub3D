/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:57:17 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Adds the node ’new’ at the end of the list.
 * @param lst // The address of a pointer to the first link of a list.
 * @param new // The address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last_node;

	last_node = ft_lstlast(*lst);
	if (last_node == NULL)
	{
		*lst = new_node;
	}
	else
	{
		last_node->next = new_node;
	}
}
