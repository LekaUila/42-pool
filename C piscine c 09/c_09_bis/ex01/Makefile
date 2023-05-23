
SRC 		= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

HEADER		= includes/ft.h

PO 			= ${SRC:.c=.o}

NAME 	= libft.a

all :		${NAME}

.c.o : $(PO)
			gcc -c -Wall -Wextra -Werror $< -o ${<:.c=.o}

${NAME}:	${PO}
			ar rc ${NAME} ${PO} ${HEADER}

clean :
			rm -f ${PO}

fclean :	clean
			rm -f ${NAME}

re :		fclean all
			


.PHONY : all clean fclean re