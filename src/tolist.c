/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:55:55 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/16 09:40:13 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*init_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->end = NULL;
	return (list);
}

void	append_tolist(t_list *list, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->num = value;
	new_node->next = NULL;
	if (list->head == NULL)
	{
		list->head = new_node;
		list->end = new_node;
	}
	else
	{
		list->end->next = new_node;
		list->end = new_node;
	}
}

int	addsplit(char **argv, int j, t_list *list)
{
	char	*input;
	char	**num;
	int		numbercheck;
	int		i;

	input = ft_strdup(argv[j]);
	if (!input)
		return (0);
	num = ft_split(input, ' ');
	if (!num)
		return (0);
	i = 0;
	while (num[i])
	{
		numbercheck = ft_atoi(num[i]);
		if (is_duplicate(list, numbercheck) || check_str(num[i]))
		{
			ft_free_split(num);
			free(input);
			return (1);
		}
		append_tolist(list, numbercheck);
		i++;
	}
	return (ft_free_split(num), free(input), 0);
}

int	add_list(t_list *list, int argc, char **argv)
{
	int		j;
	int		numbercheck;

	j = 1;
	while (j < argc)
	{
		if (ft_strchr(argv[j], ' '))
		{
			if (addsplit(argv, j, list))
				return (1);
		}
		else
		{
			numbercheck = ft_atoi(argv[j]);
			if (is_duplicate(list, numbercheck) || check_str(argv[j]))
				return (1);
			append_tolist(list, numbercheck);
		}
		j++;
	}
	return (0);
}
