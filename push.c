/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:19:50 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 14:19:51 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*a_first;
	t_list	*b_first;

	a_first = *a;
	b_first = *b;
	if (!b_first)
		return ;
	if (b_first->next)
		b_first->next->previous = NULL;
	*b = b_first->next;
	if (a_first)
		a_first->previous = b_first;
	b_first->next = a_first;
	*a = b_first;
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
