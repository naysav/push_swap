/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:15:32 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 18:15:33 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **a)
{
	t_list	*a_temp;

	a_temp = *a;
	while (a_temp->next)
	{
		if (a_temp->next->order < a_temp->order)
			return (0);
		a_temp = a_temp->next;
	}
	return (1);
}

int	is_sorted_and_b(t_list **a, t_list **b)
{
	t_list	*a_temp;
	t_list	*b_temp;

	b_temp = *b;
	if (b_temp)
		return (0);
	a_temp = *a;
	while (a_temp->next)
	{
		if (a_temp->next->order < a_temp->order)
			return (0);
		a_temp = a_temp->next;
	}
	return (1);
}

int	find_max(t_list **a)
{
	t_list	*temp;
	int		max;

	temp = *a;
	max = 0;
	while (temp)
	{
		if (temp->order > max)
			max = temp->order;
		temp = temp->next;
	}
	return (max);
}
