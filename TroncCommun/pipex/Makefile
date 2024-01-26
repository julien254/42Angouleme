# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2024/01/25 12:45:29 by judetre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

NAME_BONUS	=	pipex_bonus

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I.

SRCS		=	pipex.c						\
				pipex_utils.c				\
				open_free.c					\
				ft_split_pipex.c

SRCS_BONUS	=	bonus/pipex_bonus.c			\
				bonus/pipex_utils_bonus.c	\
				bonus/open_free_bonus.c		\
				bonus/pipex_heredoc.c		\
				bonus/ft_split_pipex_bonus.c

OBJS		= 	${SRCS:.c=.o}

OBJS_BONUS	= 	${SRCS_BONUS:.c=.o}

LIBPATH		= 	libft/

all:			${NAME}

${NAME}:		${OBJS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ -L./libft -lft -o $@

bonus:			${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ -L./libft -lft -o ${NAME_BONUS}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
			make fclean -C ${LIBPATH}
			rm -f ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY:			all clean fclean re
