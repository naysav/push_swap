/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:18 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 14:20:19 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **list)
{
	t_list	*first;
	t_list	*last;

	first = *list;
	if (!first || !first->next)
		return ;
	last = find_last_elem(first);
	first->next->previous = NULL;
	*list = first->next;
	first->previous = last;
	first->next = NULL;
	last->next = first;
}

void	ra(t_list **list)
{
	rotate(list);
	write(1, "ra\n", 3);
}

void	rb(t_list **list)
{
	rotate(list);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
