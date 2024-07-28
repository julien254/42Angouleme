# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 16:35:18 by jdetre            #+#    #+#              #
#    Updated: 2024/07/11 12:35:20 by jdetre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

NAME_BONUS	=	

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I.

LIB			=	-L${LIBPATH} -lft -L${MLXPATH} -lmlx_Linux -lXext -lX11 -lm -lz

SRCS		=	so_long.c		\
				so_long_loop.c	\
				so_long_hook.c	\
				exit_game.c		\
				check_map.c 	\
				map_utils.c		\
				pixel_utils.c	\
				img_load.c		\
				bitmask_utils.c	\
				verif_way.c		\
				init_way.c

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

clean:
			make clean -C ${LIBPATH}
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
			make fclean -C ${LIBPATH}
			make clean -C ${MLXPATH}
			rm -f ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY:			all clean fclean re
