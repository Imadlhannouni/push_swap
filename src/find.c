/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:28:51 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/21 13:36:38 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_pos(t_list *list)
{
	t_node	*temp;
	int		max;
	int		pos;
	int		i;

	temp = list->head;
	max = INT_MIN;
	pos = 1;
	i = 1;
	while (temp != NULL)
	{
		if (temp->num > max)
		{
			max = temp->num;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

int	find_min_pos(t_list *list)
{
	t_node	*temp;
	int		min;
	int		pos;
	int		i;

	temp = list->head;
	min = INT_MAX;
	pos = 1;
	i = 1;
	while (temp != NULL)
	{
		if (temp->num < min)
		{
			min = temp->num;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

int	find_min(t_list *list)
{
	t_node	*current;
	int		min;

	if (!list->head)
		return (0);
	current = list->head;
	min = current->num;
	while (current)
	{
		if (current->num < min)
			min = current->num;
		current = current->next;
	}
	return (min);
}

int	find_max(t_list *list)
{
	t_node	*current;
	int		max;

	if (!list->head)
		return (0);
	current = list->head;
	max = current->num;
	while (current)
	{
		if (current->num > max)
			max = current->num;
		current = current->next;
	}
	return (max);
}

int	find_insertion_pos(t_list *a, int num)
{
	t_node	*current;
	int		pos;
	int		prev_num;
	int		min_num;
	int		max_num;

	current = a->head;
	pos = 1;
	min_num = find_min(a);
	max_num = find_max(a);
	if (num < min_num || num > max_num)
		return (find_min_pos(a));
	prev_num = a->end->num;
	while (current)
	{
		if (num > prev_num && num < current->num)
			return (pos);
		prev_num = current->num;
		current = current->next;
		pos++;
	}
	return (1);
}
