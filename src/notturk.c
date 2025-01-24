/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notturk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:07:59 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/21 13:37:39 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_to_top(t_list *list, int pos, char stack_name)
{
	int		size;

	size = countsize(list, 0);
	if (pos <= size / 2)
	{
		while (--pos)
		{
			rotate(list);
			ft_printf("r%c\n", stack_name);
		}
	}
	else
	{
		while (pos++ <= size)
		{
			inv_rotate(list);
			ft_printf("rr%c\n", stack_name);
		}
	}
}

void	find_best_move(t_list *a, t_list *b, int *pos_a, int *pos_b)
{
	t_node	*current_b;
	int		current_pos_b;
	int		target_pos_a;
	int		min_cost;
	int		total_cost;

	min_cost = INT_MAX;
	current_b = b->head;
	current_pos_b = 1;
	while (current_b)
	{
		target_pos_a = find_insertion_pos(a, current_b->num);
		total_cost = calculate_cost_a(a, target_pos_a)
			+ calculate_cost_b(b, current_pos_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			*pos_a = target_pos_a;
			*pos_b = current_pos_b;
		}
		current_b = current_b->next;
		current_pos_b++;
	}
}

void	execute_moves(t_list *a, t_list *b, int pos_a, int pos_b)
{
	int	size_a;
	int	size_b;

	size_a = countsize(a, 0);
	size_b = countsize(b, 0);
	while (pos_a > 1 && pos_a <= size_a / 2
		&& pos_b > 1 && pos_b <= size_b / 2)
	{
		rr(a, b);
		ft_printf("rr\n");
		pos_a--;
		pos_b--;
	}
	while (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		rrr(a, b);
		ft_printf("rrr\n");
		pos_a = (pos_a % size_a) + 1;
		pos_b = (pos_b % size_b) + 1;
	}
	rotate_to_top(a, pos_a, 'a');
	rotate_to_top(b, pos_b, 'b');
}

int	push_swap(t_list *a, t_list *b)
{
	int	pos_a;
	int	pos_b;
	int	min_pos;

	while (countsize(a, 0) > 3)
	{
		pushb(a, b);
		ft_printf("pb\n");
	}
	list3(a);
	while (b->head)
	{
		find_best_move(a, b, &pos_a, &pos_b);
		execute_moves(a, b, pos_a, pos_b);
		pusha(b, a);
		ft_printf("pa\n");
	}
	min_pos = find_min_pos(a);
	rotate_to_top(a, min_pos, 'a');
	return (0);
}
