#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	int				order;
	int				flag;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct s_info
{
	int	next;
	int	mid;
	int	max;
	int	flag;
}	t_info;

/*
list_utils.c
*/

t_list	*create_list(int num);
void	free_list(t_list **list);
void	push_front(t_list **a, int num);
t_list	*find_last_elem(t_list *list);

/*
parsing_and_checking.c
*/

void	error_treatment(t_list **a);
int		atoi_for_list(t_list **a, char *str);
void	parsing_arguments(t_list **a, int argc, char **argv);
int		is_sorted(t_list **a);

/*
push_swap.c
*/

#endif