/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:47:15 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/16 20:37:14 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_list *lst, t_list *lst2)
{
	if (lst)
		swap(lst);
	if (lst2)
		swap(lst2);
}

void	rr(t_list *lst, t_list *lst2)
{
	if (lst)
		rotate(lst);
	if (lst2)
		rotate(lst2);
}

void	rrr(t_list *lst, t_list *lst2)
{
	if (lst)
		inv_rotate(lst);
	if (lst2)
		inv_rotate(lst2);
}

void	pushto_array(int *array, int size, t_node *temp)
{
	int	i;

	i = 0;
	while (i < size && temp != NULL)
	{
		array[i] = temp->num;
		temp = temp->next;
		i++;
	}
}
