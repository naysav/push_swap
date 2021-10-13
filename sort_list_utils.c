/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:15:13 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 18:15:14 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort_list(t_list **a, int argc)
{
	t_list	*list;
	t_list	*temp;
	int		max;

	argc--;
	while (argc)
	{
		list = *a;
		max = -2147483648;
		while (list)
		{
			if (!list->order && list->num >= max)
			{
				temp = list;
				max = list->num;
			}
			list = list->next;
		}
		temp->order = argc;
		argc--;
	}
}

void	right_to_left_cycle(t_list **a, t_list **b, t_info *info)
{
	t_list	*b_first;

	b_first = *b;
	if (b_first->order == info->next)
	{
		info->next++;
		b_first->flag = info->flag;
		pa(a, b);
		ra(a);
		return ;
	}
	else if (b_first->order >= info->mid)
	{
		b_first->flag = info->flag;
		pa(a, b);
	}
}

void	right_to_left(t_list **a, t_list **b, t_info *info)
{
	t_list	*b_first;
	t_list	*b_last;

	b_first = *b;
	if (!b_first)
		return ;
	b_last = find_last_elem(b_first);
	info->max = info->mid;
	info->mid = ((info->max - info->next) / 2) + info->next;
	info->flag++;
	while (b_first != b_last)
	{
		b_first = *b;
		if (!(b_first->order == info->next || b_first->order >= info->mid))
			rb(b);
		else
			right_to_left_cycle(a, b, info);
	}
	if (*b)
		right_to_left_cycle(a, b, info);
}

void	left_to_right_cycle(t_list **a, t_list **b, t_info *info)
{
	t_list	*a_first;
	int		flag;

	a_first = *a;
	flag = a_first->flag;
	if (a_first->order == info->next)
	{
		info->next++;
		ra(a);
	}
	else if (a_first->flag == flag)
		pb(a, b);
}

void	left_to_right(t_list **a, t_list **b, t_info *info)
{
	t_list	*a_first;
	t_list	*a_last;
	int		flag;

	a_first = *a;
	a_last = find_last_elem(a_first);
	flag = a_first->flag;
	while (a_first != a_last)
	{
		a_first = *a;
		if (a_first->flag != flag)
			return ;
		left_to_right_cycle(a, b, info);
	}
	a_first = *a;
	left_to_right_cycle(a, b, info);
}
