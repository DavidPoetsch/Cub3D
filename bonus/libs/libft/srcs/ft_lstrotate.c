/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:13:31 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Rotate the list. The first element becomes the last one.
 * @param **head The pointer to the lists head
 */
void	ft_lstrotate(t_list **head)
{
	t_list	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	last = ft_lstlast(*head);
	last->next = *head;
	*head = (*head)->next;
	last->next->next = NULL;
}
