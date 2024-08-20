# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 00:31:09 by judetre           #+#    #+#              #
#    Updated: 2024/08/19 12:42:31 by judetre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo	

NAME_BONUS	=	

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g -pthread #-fsanitize=thread

INCLUDE		=	-I.

LIB			=	

SRCS		=	philo.c			\
				philo_utils.c	\
				philo_routine.c	\
				philo_action.c	\
				forks_utils.c	\
				monitoring.c	\
				utils.c			\
				print.c			\
				init.c			\
				set.c			\
				free.c

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
