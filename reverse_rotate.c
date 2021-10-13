/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:21 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 14:20:22 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **list)
{
	t_list	*first;
	t_list	*last;

	first = *list;
	if (!first || !first->next)
		return ;
	last = find_last_elem(first);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = first;
	first->previous = last;
	*list = last;
}

void	rra(t_list **list)
{
	reverse_rotate(list);
	write(1, "rra\n", 4);
}

void	rrb(t_list **list)
{
	reverse_rotate(list);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
