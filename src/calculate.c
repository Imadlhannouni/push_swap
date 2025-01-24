/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:38:04 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/19 15:38:24 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculate_cost_a(t_list *a, int pos)
{
	int	size;
	int	forward;
	int	backward;

	size = countsize(a, 0);
	forward = pos - 1;
	backward = size - pos + 1;
	if (forward < backward)
		return (forward);
	else
		return (backward);
}

int	calculate_cost_b(t_list *b, int pos)
{
	int	size;
	int	forward;
	int	backward;

	size = countsize(b, 0);
	forward = pos - 1;
	backward = size - pos + 1;
	if (forward < backward)
		return (forward);
	else
		return (backward);
}
