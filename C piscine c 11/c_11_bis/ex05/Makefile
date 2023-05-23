# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 09:24:04 by nlocusso          #+#    #+#              #
#    Updated: 2022/08/01 14:53:34 by lflandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c operator.c converter.c

PO 			= ${SRCS:.c=.o}

NAME	= do-op

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
