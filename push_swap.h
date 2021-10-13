/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:19:39 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 18:04:33 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	int				order;
	int				flag;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct s_info
{
	int	next;
	int	mid;
	int	max;
	int	flag;
}	t_info;

//parsing_arguments.c
int		check_sorted(t_list **a);
void	error(t_list **a);
int		push_swap_atoi(t_list **a, char *str);
void	parsing_arguments(t_list **a, int argc, char **argv);

//small_sort.c
void	sort_3_numbers(t_list **a);
void	sort_4_numbers(t_list **a, t_list **b);
void	sort_5_numbers(t_list **a, t_list **b);

//swap.c
void	swap(t_list **list);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

//push.c
void	push(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

//rotate.c
void	rotate(t_list **list);
void	ra(t_list **list);
void	rb(t_list **list);
void	rr(t_list **a, t_list **b);

//reverse_rotate.c
void	reverse_rotate(t_list **list);
void	rra(t_list **list);
void	rrb(t_list **list);
void	rrr(t_list **a, t_list **b);

//list_utils.c
t_list	*find_last_elem(t_list *list);
int		list_len(t_list *list);
void	free_list(t_list **list);
t_list	*create_list(int num);
void	push_front(t_list **a, int num);

//check_list.c
int		is_sorted(t_list **a);
int		is_sorted_and_b(t_list **a, t_list **b);
int		find_max(t_list **a);

//sort_lists_utils.c
void	presort_list(t_list **a, int argc);
void	right_to_left_cycle(t_list **a, t_list **b, t_info *info);
void	right_to_left(t_list **a, t_list **b, t_info *info);
void	left_to_right_cycle(t_list **a, t_list **b, t_info *info);
void	left_to_right(t_list **a, t_list **b, t_info *info);

//sort_list.c
void	first_iteration(t_list **a, t_list **b, t_info *info);
t_info	*init_info(int argc);
void	sort_list(t_list **a, t_list **b, int argc);

#endif
