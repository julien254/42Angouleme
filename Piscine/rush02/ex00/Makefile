# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matandre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 19:02:29 by matandre          #+#    #+#              #
#    Updated: 2022/03/27 18:57:22 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	rush-02

CFLAGS = -Wall -Werror -Wextra -I includes

SRCS =	ft_atoi.c \
		ft_check_0_in_rank.c \
		ft_cut_print_pattern.c \
		ft_dico.c \
		ft_initstr.c \
		ft_modulo.c \
		ft_put.c \
		ft_strlen.c \
		ft_temp.c \
		ft_if_str_same_pattern.c \
		main.c

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
	gcc ${CFLAGS} $^ -o $@

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re : fclean all

.PHONY: re all fclean clean