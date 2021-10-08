SRCS =	push_swap.c				\
		list_utils.c			\
		parsing_and_checking.c	

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