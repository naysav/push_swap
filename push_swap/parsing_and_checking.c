#include "push_swap.h"

void	error_treatment(t_list **a)
{
	free_list(a);
	write(1, "Error\n", 6);
	exit(1);
}

int	atoi_for_list(t_list **a, char *str)
{
	size_t	count;
	int		sign;

	count = 0;
	sign = 0;
	if (*str == '-')
		sign = 1, str++;
	if (!*str)
		error_treatment(a);
	while (*str >= '0' && *str <= '9')
	{
		count = count * 10 + *str - '0';
		if ((sign && count > 2147483648) || (!sign && count > 2147483647))
			error_treatment(a);
		str++;
	}
	if (*str)
		error_treatment(a);
	printf("atoi: %zu\n", count);
	if (sign)
		return (-count);
	return (count);
}

void	parsing_arguments(t_list **a, int argc, char **argv)
{
	printf("parsing_arguments\n");
	while (argc > 0)
		push_front(a, atoi_for_list(a, argv[argc--]));
}

int	is_sorted(t_list **a)
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
				error_treatment(a);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	printf("check: %d\n", sorted);
	return (sorted);
}
