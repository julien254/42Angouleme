# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2022/10/13 20:17:30 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

NAME_BONUS	=	so_long_bonus

NAME_TEST	=	so_long_test

CC			=	gcc -g

CFLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I.

LIB			=	-L./libft -lft -L. -lmlx -lXext -lX11 -lm -lz

SRCS		=	so_long.c						\
				so_long_img.c					\
				so_long_map.c					\
				so_long_check.c					\
				so_long_err.c					\
				so_long_init.c					\
				so_long_utils.c					\
				so_long_close.c					\
				so_long_way.c					\
				so_long_map2d.c

SRCS_BONUS	=	bonus/so_long_bonus.c			\
				bonus/so_long_img_bonus.c		\
				bonus/so_long_map_bonus.c		\
				bonus/so_long_check_bonus.c		\
				bonus/move_down.c				\
				bonus/move_up.c					\
				so_long_err.c					\
				bonus/so_long_init_bonus.c		\
				bonus/so_long_utils_bonus.c		\
				so_long_close.c					\
				so_long_way.c					\
				so_long_map2d.c

OBJS		= 	${SRCS:.c=.o}

OBJS_BONUS	= 	${SRCS_BONUS:.c=.o}

LIBPATH		= 	libft/

all:			${NAME}

${NAME}:		${OBJS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB} -o $@

bonus:			${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB} -o ${NAME_BONUS}

test:			${NAME_TEST}

${NAME_TEST}:	${OBJS_BONUS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB} -o ${NAME_TEST}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
			make fclean -C ${LIBPATH}
			rm -f ${NAME} ${NAME_BONUS} ${NAME_TEST}

re:				fclean all

.PHONY:			all clean fclean re
