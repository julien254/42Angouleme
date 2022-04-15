# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2022/04/15 15:14:58 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc -g

CFLAGS		= -Wall -Wextra -Werror -I.

SRCS		= ${wildcard ft_*.c}

OBJS		= ${SRCS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus:		${OBJS}
	ar rcs ${NAME} ${OBJS} 


clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
