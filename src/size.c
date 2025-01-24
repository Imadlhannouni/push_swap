/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:47:58 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/14 14:10:57 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	countsize(t_list *list, int counter)
{
	t_node	*current;

	current = list->head;
	while (current != NULL)
	{
		counter++;
		current = current->next;
	}
	return (counter);
}
