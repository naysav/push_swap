#include "push_swap.h"

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%d ", list->num);
		list = list->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	// t_list	*b_stack;

	parsing_arguments(&a_stack, argc - 1, argv);
	if (is_sorted(&a_stack))
		return (0);
	printf("heh\n");
	print_list(a_stack);
	return (0);
}
