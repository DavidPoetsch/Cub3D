/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:13:31 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Push the first element from a list to the front of another list
 * @param lst_a Head of list a
 * @param lst_b Head of list b
 */
void	ft_lstpushfirst(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (!lst_a || !(*lst_a))
		return ;
	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(lst_b, tmp);
}
