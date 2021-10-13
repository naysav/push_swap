/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:40 by ralena            #+#    #+#             */
/*   Updated: 2021/10/13 18:05:00 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last_elem(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

int	list_len(t_list *list)
{
	int	i;

	i = 1;
	while (list->next)
		list = list->next, i++;
	return (i);
}

void	free_list(t_list **list)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *list;
	if (!temp1)
		return ;
	temp2 = temp1->next;
	while (temp2)
	{
		free(temp1);
		temp1 = temp2;
		temp2 = temp1->next;
	}
	free(temp1);
}

t_list	*create_list(int num)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		exit(1);
	list->num = num;
	list->order = 0;
	list->flag = 0;
	list->next = NULL;
	list->previous = NULL;
	return (list);
}

void	push_front(t_list **a, int num)
{
	t_list	*list;
	t_list	*temp;

	list = create_list(num);
	temp = *a;
	if (temp)
	{
		temp->previous = list;
		list->next = temp;
	}
	*a = list;
}
