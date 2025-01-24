/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:29:49 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/14 15:06:27 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_lstlast(t_list *lst)
{
	t_node	*current;

	if (!lst || !lst->head)
		return (NULL);
	current = lst->head;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	ft_lstdelone(t_node *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del((void *)lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_node	*current;
	t_node	*next;

	if (!lst || !del)
		return ;
	current = (*lst)->head;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	(*lst)->head = NULL;
}
