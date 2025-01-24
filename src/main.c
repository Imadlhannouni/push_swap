/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:55:24 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/20 10:25:49 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_list *(list), *(list2);
	int (error), (size);
	if (argc >= 2)
	{
		list = init_list();
		list2 = init_list();
		error = add_list(list, argc, argv);
		size = countsize(list, 0);
		if (error == 1 || size == 0)
			return (clearall(list, list2), 1);
		if (checkif_sorted(list))
			return (freeall(&list), freeall(&list2), 0);
		if (size > 1 && size <= 3)
			list3(list);
		else if (size > 3 && size <= 5)
			sort_five_numbers(list, list2);
		else if (size > 5)
			push_swap(list, list2);
		freeall(&list);
		freeall(&list2);
	}
	else
		return (0);
	return (0);
}
