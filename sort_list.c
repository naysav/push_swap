/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:15:22 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 18:15:24 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*init_info(int argc)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		exit(1);
	info->next = 1;
	info->max = argc - 1;
	info->mid = (info->max / 2) + info->next;
	info->flag = 0;
	return (info);
}

void	first_iteration(t_list **a, t_list **b, t_info *info)
{
	t_list	*a_first;
	t_list	*a_last;

	a_first = *a;
	a_last = find_last_elem(a_first);
	while (a_first != a_last)
	{
		a_first = *a;
		if (a_first->order <= info->mid)
			pb(a, b);
		else
			ra(a);
	}
	a_first = *a;
	if (a_first->order <= info->mid)
		pb(a, b);
}

void	sort_list(t_list **a, t_list **b, int argc)
{
	t_info	*info;

	info = init_info(argc);
	first_iteration(a, b, info);
	while (!is_sorted_and_b(a, b))
	{
		info->mid = find_max(b);
		while (*b)
			right_to_left(a, b, info);
		if (!is_sorted(a))
			left_to_right(a, b, info);
	}
	free(info);
}
