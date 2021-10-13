/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:19:59 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 14:20:00 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*first_elem;
	t_list	*second_elem;

	first_elem = *list;
	if (!first_elem || !first_elem->next)
		return ;
	second_elem = first_elem->next;
	if (second_elem->next)
		second_elem->next->previous = first_elem;
	first_elem->next = second_elem->next;
	first_elem->previous = second_elem;
	second_elem->next = first_elem;
	second_elem->previous = NULL;
	*list = second_elem;
}

void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
