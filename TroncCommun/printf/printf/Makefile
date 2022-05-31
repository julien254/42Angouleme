# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2022/05/31 14:43:58 by jdetre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I.

SRCS		= ft_printf.c

OBJS		= ${SRCS:.c=.o}

LIBPATH		= libft/

all:		${NAME}

${NAME}:	${OBJS}
	make -C ${LIBPATH}
	mv ${LIBPATH}libft.a ${NAME}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:		clean
	make fclean -C ${LIBPATH}
	rm -f ${NAME} libft.a

re:			fclean all

.PHONY:		all clean fclean re
