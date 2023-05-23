
SRC 		= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

HEADER		= includes/ft.h

PO 			= ${SRC:.c=.o}

LIBNAME 	= libft.a

.c.o :
			cc -c -Wall -Wextra -Werror $< -o ${<:.c=.o}

${LIBNAME}:	${PO}
			ar rc ${LIBNAME} ${PO} ${HEADER}

all :		${LIBNAME}

clean :
			rm -f ${PO}

fclean :	clean
			rm -f ${LIBNAME}

re :		fclean all
			


.PHONY : all clean fclean re