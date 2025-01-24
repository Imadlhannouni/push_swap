/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:31:47 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/08 13:44:26 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_current(void *current)
{
	free(current);
}

void	freeall(t_list **list)
{
	if (list && *list)
	{
		ft_lstclear(list, free_current);
		free(*list);
		*list = NULL;
	}
}

void	ft_free_split(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
