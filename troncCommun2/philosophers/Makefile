# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 00:31:09 by judetre           #+#    #+#              #
#    Updated: 2024/08/15 14:59:38 by judetre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo	

NAME_BONUS	=	

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g -pthread #-fsanitize=thread

INCLUDE		=	-I.

LIB			=	

SRCS		=	philo.c

SRCS_BONUS	=	

OBJS		= 	${SRCS:.c=.o}

OBJS_BONUS	= 	${SRCS_BONUS:.c=.o}

LIBPATH		= 	

all:			${NAME}

${NAME}:		${OBJS}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB} -o $@

bonus:			${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB} -o ${NAME_BONUS}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
			rm -f ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY:			all clean fclean re
