# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2022/04/16 13:43:18 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc -g

CFLAGS		= -Wall -Wextra -Werror -I.

SRCS		= ${wildcard *.c}

OBJS		= ${SRCS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus:		${OBJS}
	ar rcs ${NAME} ${OBJS}

so:
	$(CC) -fPIC $(CFLAGS) $(SRCS)
	gcc -shared -o libft.so $(OBJS)

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
