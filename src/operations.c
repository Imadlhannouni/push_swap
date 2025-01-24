/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:55:21 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/16 11:48:41 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list *lst)
{
	t_node	*first;
	t_node	*second;

	if (lst->head && lst->head->next)
	{
		first = lst->head;
		second = first->next;
		first->next = second->next;
		second->next = first;
		lst->head = second;
	}
}

void	pushb(t_list *lst, t_list *lst2)
{
	t_node	*to_push;

	if (lst->head)
	{
		to_push = lst->head;
		lst->head = lst->head->next;
		to_push->next = lst2->head;
		lst2->head = to_push;
		if (to_push->next == NULL)
			lst2->end = to_push;
		else
		{
			while (lst2->end && lst2->end->next != NULL)
				lst2->end = lst2->end->next;
		}
	}
}

void	pusha(t_list *lst2, t_list *lst)
{
	t_node	*to_push;

	if (lst2->head && lst2->head->next)
	{
		to_push = lst2->head;
		lst2->head = lst2->head->next;
		to_push->next = lst->head;
		lst->head = to_push;
	}
	else if (lst2->head && lst2->head->next == NULL)
	{
		to_push = lst2->head;
		to_push->next = lst->head;
		lst->head = to_push;
		lst2->head = NULL;
	}
	if (lst2->head == NULL)
		lst2->end = NULL;
	else
	{
		lst2->end = ft_lstlast(lst2);
	}
}

void	rotate(t_list *lst)
{
	t_node	*to_rotate;
	t_node	*last;

	if (lst->head && lst->head->next)
	{
		to_rotate = lst->head;
		lst->head = lst->head->next;
		last = ft_lstlast(lst);
		last->next = to_rotate;
		to_rotate->next = NULL;
		lst->end = to_rotate;
	}
}

void	inv_rotate(t_list *lst)
{
	t_node	*newlast;
	t_node	*last;

	if (lst->head && lst->head->next)
	{	
		last = lst->head;
		newlast = NULL;
		while (last->next)
		{
			newlast = last;
			last = last->next;
		}
		newlast->next = NULL;
		last->next = lst->head;
		lst->head = last;
		lst->end = newlast;
	}
}
