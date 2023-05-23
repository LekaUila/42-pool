# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 09:24:04 by nlocusso          #+#    #+#              #
#    Updated: 2022/08/03 14:43:35 by lflandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_mapcmp.c ft_is_printable.c ft_contain_only.c ft_write_map.c file_reader.c ft_putstr.c find_square.c standart_entry_reader.c ft_strstr.c ft_tablen.c ft_strndup.c main.c ft_atou.c ft_strlen.c ft_is_digit.c ft_duplicated.c ft_split.c map_reader.c ft_strcat.c


PO 			= ${SRCS:.c=.o}

NAME	= bsq

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
