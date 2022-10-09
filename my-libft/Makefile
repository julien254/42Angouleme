# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2022/10/09 05:56:17 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	

NAME_BONUS	=	

NAME_TEST	=	

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I.

LIB			=	-L./libft -lft

SRCS		=	

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
			${CC} -g ${CFLAGS} $^ ${INCLUDE} ${LIB} -o ${NAME_TEST}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
			make fclean -C ${LIBPATH}
			rm -f ${NAME} ${NAME_BONUS} ${NAME_TEST}

re:				fclean all

.PHONY:			all clean fclean re
