/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:29:43 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/16 20:06:39 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clearall(t_list *list, t_list *list2)
{
	freeall(&list);
	freeall(&list2);
	write(2, "Error\n", 6);
}

int	is_duplicate(t_list *list, int number)
{
	t_node	*current;

	current = list->head;
	while (current != NULL)
	{
		if (current->num == number)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_str(char *str)
{
	int		i;
	long	num;

	if (str[0] == '\0' || (str[0] == '+' && str[1] == '\0')
		|| (str[0] == '-' && str[1] == '\0'))
		return (1);
	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
		return (1);
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	checkif_sorted(t_list *list)
{
	int		flag;
	t_node	*temp;

	flag = 0;
	temp = list->head;
	while (temp->next != NULL)
	{
		if (temp->num < temp->next->num)
			flag = 1;
		else
		{
			return (0);
		}
		temp = temp->next;
	}
	if (flag == 1)
		return (1);
	return (0);
}
