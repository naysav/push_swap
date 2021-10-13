SRCS =	push.c				\
		parsing_arguments.c	\
		push_swap.c			\
		small_sort.c		\
		rotate.c			\
		reverse_rotate.c	\
		check_list.c		\
		sort_list.c			\
		sort_list_utils.c	\
		swap.c				\
		list_utils.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap
P_HEAD = push_swap.h

RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

%.o: %.c
	${CC} ${CFLAGS} -c $< -I ${P_HEAD} -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re