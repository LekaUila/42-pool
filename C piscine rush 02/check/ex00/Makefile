# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 09:24:04 by nlocusso          #+#    #+#              #
#    Updated: 2022/07/31 15:37:05 by lflandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c delete_space.c check_dict.c reader.c ft_put_nbr.c ft_put_nbr2.c strstr.c check_key.c

PO 			= ${SRCS:.c=.o}

NAME	= rush-02

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
