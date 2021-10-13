/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:19:47 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 17:52:12 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_numbers(t_list **a)
{
	t_list	*temp;

	temp = *a;
	if (temp->num < temp->next->num && temp->num < temp->next->next->num)
		sa(a), ra(a);
	else if (temp->num > temp->next->num && temp->num > temp->next->next->num)
	{
		if (temp->next->num < temp->next->next->num)
			ra(a);
		else
			sa(a), rra(a);
	}
	else
	{
		if (temp->next->num < temp->next->next->num)
			sa(a);
		else
			rra(a);
	}
}

void	sort_4_numbers(t_list **a, t_list **b)
{
	while (list_len(*a) > 3)
	{
		if ((*a)->order == 1)
			pb(a, b);
		else
			ra(a);
	}
	if (!is_sorted(a))
		sort_3_numbers(a);
	pa(a, b);
}

void	sort_5_numbers(t_list **a, t_list **b)
{
	while (list_len(*a) > 3)
	{
		if ((*a)->order == 1 || (*a)->order == 2)
			pb(a, b);
		else
			ra(a);
	}
	if (!is_sorted(a))
		sort_3_numbers(a);
	if ((*b)->num < (*b)->next->num)
		rb(b);
	pa(a, b);
	pa(a, b);
}
