# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2024/07/27 14:05:16 by jdetre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap	

NAME_BONUS	=	

CC			=	gcc -g

CFLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I.

LIB			=	-L./libft -lft

SRCS		=	push_swap.c		\
				instructions.c	\
				moves.c			\
				stack_utils.c	\
				bit_utils.c		\
				sort.c
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

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
			make fclean -C ${LIBPATH}
			rm -f ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY:			all clean fclean re
