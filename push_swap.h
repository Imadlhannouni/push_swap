/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:58:08 by ilhannou          #+#    #+#             */
/*   Updated: 2025/01/20 11:11:00 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*end;
}	t_list;

t_list	*init_list(void);
int		add_list(t_list *list, int argc, char **argv);
void	freeall(t_list **list);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_node	*ft_lstlast(t_list *lst);
int		is_duplicate(t_list *list, int number);
int		check_str(char *str);
void	clearall(t_list *list, t_list *list2);
long	ft_atoi(const char *nptr);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_free_split(char **array);
void	swap(t_list *lst);
void	ss(t_list *lst, t_list *lst2);
void	pushb(t_list *lst, t_list *lst2);
void	pusha(t_list *lst2, t_list *lst);
void	rotate(t_list *lst);
void	rr(t_list *lst, t_list *lst2);
void	inv_rotate(t_list *lst);
void	rrr(t_list *lst, t_list *lst2);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		push_swap(t_list *list, t_list *list2);
int		countsize(t_list *list, int counter);
int		find_max_pos(t_list *list);
int		find_min_pos(t_list *list);
int		checkif_sorted(t_list *list);
void	list3(t_list *list);
void	sort_five_numbers(t_list *list, t_list *list2);
int		calculate_cost_a(t_list *a, int pos);
int		calculate_cost_b(t_list *b, int pos);
int		find_min(t_list *list);
int		find_max(t_list *list);
int		find_insertion_pos(t_list *a, int num);
char	*get_next_line(int fd);

#endif