# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 08:24:44 by lflandri          #+#    #+#              #
#    Updated: 2022/08/01 08:54:21 by lflandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c

PO 		= ${SRCS:.c=.o}

NAME	= ft_cat

all	:	${NAME}

${NAME}:	${PO}
			gcc -o ${NAME} -Wall -Wextra -Werror ${PO}

.c.o : $(PO)
			gcc -c -Wall -Wextra -Werror $< -o ${<:.c=.o}

clean	:
			rm -f ${PO}

fclean	:	clean
			rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re