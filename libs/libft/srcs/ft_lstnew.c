/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:13:31 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new node.
					The member variable ’content’ is initialized with
					the value of the parameter ’content’. The variable
					’next’ is initialized to NULL.
 * @param content The content to create the node with.
 * @return t_list* The new node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
