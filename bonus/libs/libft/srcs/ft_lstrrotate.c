/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:13:31 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Rotate the list. The last element becomes the first one.
 * @param **head The pointer to the lists head
 */
void	ft_lstrrotate(t_list **head)
{
	t_list	*current;
	t_list	*new_head;

	if (!head || !*head || !(*head)->next)
		return ;
	current = *head;
	while (current->next->next)
	{
		current = current->next;
	}
	new_head = current->next;
	new_head->next = *head;
	*head = new_head;
	current->next = NULL;
}
