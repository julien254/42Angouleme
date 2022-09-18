# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2022/09/18 17:17:46 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

CC			= gcc -g

CFLAGS		= -Wall -Wextra -Werror -I.

SRCS		= pipex.c pipex_utils.c open_free.c

SRCS_BONUS		= bonus/pipex_bonus.c		\
				  bonus/pipex_utils_bonus.c	\
				  bonus/open_free_bonus.c	\
				  bonus/pipex_heredoc.c

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS		= ${SRCS_BONUS:.c=.o}

LIBPATH		= libft/

all:		${NAME}

${NAME}:	${OBJS}
	make -C ${LIBPATH}
	${CC} ${CFLAGS} $^ -L./libft -lft -o $@

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
