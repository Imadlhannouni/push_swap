/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notturk2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:21:25 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/20 10:31:22 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_three_cases(t_list *list, int case_num)
{
	if (case_num == 1)
	{
		inv_rotate(list);
		swap(list);
		ft_printf("rra\nsa\n");
	}
	else if (case_num == 2)
	{
		rotate(list);
		ft_printf("ra\n");
		if (list->head->num > list->head->next->num)
		{
			swap(list);
			ft_printf("sa\n");
		}
	}
	else if (case_num == 3)
	{
		swap(list);
		ft_printf("sa\n");
	}
}

void	list3(t_list *list)
{
	if (!list || !list->head || !list->head->next || !list->end)
		return ;
	if (list->head->num < list->end->num
		&& list->end->num < list->head->next->num)
		handle_three_cases(list, 1);
	else if (list->head->num > list->head->next->num
		&& list->head->num > list->end->num)
		handle_three_cases(list, 2);
	else if (list->head->num > list->head->next->num
		&& list->head->num < list->end->num)
		handle_three_cases(list, 3);
	else if (list->end->num < list->head->num
		&& list->end->num < list->head->next->num)
	{
		inv_rotate(list);
		ft_printf("rra\n");
	}
}

void	handle_min_position(t_list *list, t_list *list2,	
	int min_pos, int list_size)
{
	if (min_pos == 1)
	{
		pushb(list, list2);
		ft_printf("pb\n");
	}
	else if (min_pos <= list_size / 2)
	{
		while (--min_pos)
		{
			rotate(list);
			ft_printf("ra\n");
		}
		pushb(list, list2);
		ft_printf("pb\n");
	}
	else
	{
		while (min_pos++ <= list_size)
		{
			inv_rotate(list);
			ft_printf("rra\n");
		}
		pushb(list, list2);
		ft_printf("pb\n");
	}
}

void	push_min_to_b(t_list *list, t_list *list2, int count)
{
	int	min_pos;
	int	list_size;

	while (count--)
	{
		list_size = countsize(list, 0);
		min_pos = find_min_pos(list);
		handle_min_position(list, list2, min_pos, list_size);
	}
}

void	sort_five_numbers(t_list *list, t_list *list2)
{
	if (!list || !list2)
		return ;
	push_min_to_b(list, list2, 2);
	list3(list);
	while (list2->head)
	{
		pusha(list2, list);
		ft_printf("pa\n");
		if (list->head->num > list->head->next->num)
		{
			swap(list);
			ft_printf("sa\n");
		}
	}
}
