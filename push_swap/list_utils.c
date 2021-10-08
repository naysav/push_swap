#include "push_swap.h"

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

t_list	*find_last_elem(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}
