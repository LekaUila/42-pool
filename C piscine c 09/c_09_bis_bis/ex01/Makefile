
SRC 		= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

INCLUDES	= includes/

PO 			= ${SRC:.c=.o}

NAME 	= libft.a

all :		${NAME}

.c.o : $(PO)
			gcc -I ${INCLUDES} -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}:	${PO}
			ar rc ${NAME} ${PO}

clean :
			rm -f ${PO}

fclean :	clean
			rm -f ${NAME}

re :		fclean all
			


.PHONY : all clean fclean re