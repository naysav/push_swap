/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:35 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 17:56:49 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list **a)
{
	t_list	*temp1;
	t_list	*temp2;
	int		sorted;

	temp1 = *a;
	sorted = 1;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (sorted && temp2->num < temp1->num)
				sorted = 0;
			if (temp1->num == temp2->num)
				error(a);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (sorted);
}

void	error(t_list **a)
{
	write(1, "Error\n", 6);
	free_list(a);
	exit(1);
}

int	push_swap_atoi(t_list **a, char *str)
{
	size_t	count;
	int		sign;

	count = 0;
	sign = 0;
	if (*str == '-')
		sign = 1, str++;
	if (!*str)
		error(a);
	while (*str >= '0' && *str <= '9')
	{
		count *= 10;
		count += *str - '0';
		if ((sign && count > 2147483648) || (!sign && count > 2147483647))
			error(a);
		str++;
	}
	if (*str)
		error(a);
	if (sign)
		return (-count);
	return (count);
}

void	parsing_arguments(t_list **a, int argc, char **argv)
{
	while (argc > 0)
		push_front(a, push_swap_atoi(a, argv[argc--]));
}
