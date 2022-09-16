# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2022/09/16 17:21:49 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

CC			= gcc -g

CFLAGS		= -Wall -Wextra -Werror -I.

SRCS		= pipex.c

OBJS		= ${SRCS:.c=.o}

LIBPATH		= libft/

all:		${NAME}

${NAME}:	${OBJS}
	make -C ${LIBPATH}
	${CC} ${CFLAGS} $^ -L./libft -lft -o $@


clean:
	rm -f ${OBJS}

fclean:		clean
	make fclean -C ${LIBPATH}
	rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
