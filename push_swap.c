/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:28 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 18:20:53 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	parsing_arguments(&a, argc - 1, argv);
	if (check_sorted(&a))
		return (0);
	presort_list(&a, argc);
	if (argc == 3 && a->num > a->next->num)
		ra(&a);
	else if (argc == 4)
		sort_3_numbers(&a);
	else if (argc == 5)
		sort_4_numbers(&a, &b);
	else if (argc == 6)
		sort_5_numbers(&a, &b);
	else
		sort_list(&a, &b, argc);
	if (argc > 1)
		free_list(&a), free_list(&b);
	return (0);
}
