# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 09:24:04 by nlocusso          #+#    #+#              #
#    Updated: 2022/07/30 09:34:28 by nlocusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 

NAME	= rush-02

all	:	${NAME}

${NAME}:	
			gcc -o ${NAME} -Wall -Wextra -Werror ${SRCS}

clean	:
			rm -f ${OBJS}

fclean	:	clean
			rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
