# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2022/09/20 18:44:01 by jdetre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc -g

CFLAGS		= -Wall -Wextra -Werror

INCLUDE		= 

LIB			= -L./libft -lft -L. -lmlx -lXext -lX11 -lm -lz

SRCS		= so_long.c

SRCS_BONUS		= 

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS		= ${SRCS_BONUS:.c=.o}

LIBPATH		= libft/

all:		${NAME}

${NAME}:	${OBJS}
	make -C ${LIBPATH}
	${CC} ${CFLAGS} $^ $(INCLUDE) $(LIB) -o $@

bonus:		${OBJS_BONUS}
	make -C ${LIBPATH}
	${CC} ${CFLAGS} $^ -L./libft -lft -o pipex


clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
	make fclean -C ${LIBPATH}
	rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
