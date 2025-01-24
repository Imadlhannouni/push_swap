/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:14:48 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/22 11:28:53 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	commande(t_list *list, t_list *list2, char *cmd)
{
	if ((ft_strcmp(cmd, "sa\n") == 0))
		swap(list);
	else if ((ft_strcmp(cmd, "sb\n") == 0))
		swap(list2);
	else if ((ft_strcmp(cmd, "ss\n") == 0))
		ss(list, list2);
	else if ((ft_strcmp(cmd, "pb\n") == 0))
		pushb(list, list2);
	else if ((ft_strcmp(cmd, "pa\n") == 0))
		pusha(list2, list);
	else if ((ft_strcmp(cmd, "ra\n") == 0))
		rotate(list);
	else if ((ft_strcmp(cmd, "rb\n") == 0))
		rotate(list2);
	else if ((ft_strcmp(cmd, "rr\n") == 0))
		rr(list, list2);
	else if ((ft_strcmp(cmd, "rra\n") == 0))
		inv_rotate(list);
	else if ((ft_strcmp(cmd, "rrb\n") == 0))
		inv_rotate(list2);
	else if ((ft_strcmp(cmd, "rrr\n") == 0))
		rrr(list, list2);
	else
		return (1);
	return (0);
}

int	check(t_list *list, t_list *list2, int size, char *line)
{
	int	error2;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		error2 = commande(list, list2, line);
		free(line);
		if (error2 == 1)
		{
			clearall(list, list2);
			return (1);
		}
	}
	if (checkif_sorted(list) || size == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_list	*list2;
	char	*line;
	int		error;
	int		size;

	if (argc >= 2)
	{
		line = NULL;
		list = init_list();
		list2 = init_list();
		error = add_list(list, argc, argv);
		size = countsize(list, 0);
		if (error == 1 || size == 0)
			return (clearall(list, list2), 1);
		if (check(list, list2, size, line))
			return (0);
		freeall(&list);
		freeall(&list2);
	}
}
