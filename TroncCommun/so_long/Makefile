# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2022/09/25 19:14:13 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

NAME_BONUS	=	so_long_bonus

NAME_TEST =	so_long_test

CC			=	gcc -g

CFLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I.

LIB			=	-L./libft -lft -L. -lmlx -lXext -lX11 -lm -lz

SRCS		=	so_long.c						\
				ft_new_img.c

SRCS_BONUS	=	

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

${NAME_TEST}:	${OBJS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB} -o ${NAME_TEST}
			./so_long_test > test; cat test | less; rm test
			make fclean

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
			make fclean -C ${LIBPATH}
			rm -f ${NAME} ${NAME_BONUS} ${NAME_RESULT}

re:				fclean all

.PHONY:			all clean fclean re
