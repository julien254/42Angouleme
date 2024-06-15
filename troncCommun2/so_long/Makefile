# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 23:56:00 by jdetre            #+#    #+#              #
#    Updated: 2024/06/15 13:19:53 by jdetre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

NAME_BONUS	=	

NAME_TEST	=	so_long_test

CC			=	cc -g

CFLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I.

LIB			=	-L${LIBPATH} -lft -L${MLXPATH} -lmlx_Linux -lXext -lX11 -lm -lz

SRCS		=	so_long.c			

SRCS_BONUS	=	

OBJS		= 	${SRCS:.c=.o}

OBJS_BONUS	= 	${SRCS_BONUS:.c=.o}

LIBPATH		= 	libft/

MLXPATH		=	mlx/

all:			${NAME}

${NAME}:		${OBJS}
			make -C ${LIBPATH}
			make -C ${MLXPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB} -o $@

bonus:			${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB} -o ${NAME_BONUS}

test :			${NAME_TEST}

${NAME_TEST}:		${OBJS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} -L${LIBPATH} -lft -o $@

clean:
			make clean -C ${LIBPATH}
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
			make fclean -C ${LIBPATH}
			make clean -C ${MLXPATH}
			rm -f ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY:			all clean fclean re
