# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2022/10/18 18:16:07 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I.

SRCS		=	ft_atoi.c					\
				ft_bzero.c					\
				ft_calloc.c					\
				ft_verif_malloc.c			\
				ft_isalnum.c				\
				ft_isalpha.c				\
				ft_isascii.c				\
				ft_isdigit.c				\
				ft_isprint.c				\
				ft_itoa.c					\
				ft_memchr.c					\
				ft_memcmp.c					\
				ft_memcpy.c					\
				ft_memmove.c				\
				ft_memset.c					\
				ft_putchar_fd.c				\
				ft_putendl_fd.c				\
				ft_putnbr_fd.c				\
				ft_putstr_fd.c				\
				ft_split.c					\
				ft_strchr.c					\
				ft_strdup.c					\
				ft_striteri.c				\
				ft_strjoin.c				\
				ft_strjoin_malloc.c			\
				ft_strlcat.c				\
				ft_strlcpy.c				\
				ft_strmcpy.c				\
				ft_strlen.c					\
				ft_strmapi.c				\
				ft_strncmp.c				\
				ft_strnstr.c				\
				ft_strrchr.c				\
				ft_strtrim.c				\
				ft_substr.c					\
				ft_tolower.c				\
				ft_toupper.c				\
				ft_printf.c					\
				get_next_line_bonus.c		\
				get_next_line_utils_bonus.c	\
				ft_puthexa_fd.c				\
				ft_put_u_nbr_fd.c			\
				ft_putadd_fd.c				\
				ft_puthexa_ll_fd.c			\
				ft_puttab2_fd.c				\
				ft_recover_fd.c				\
				ft_count_line.c				\
				ft_line_size.c				\
				ft_line_size_max.c			\
				ft_tab2dlen.c				\
				ft_cpy_tab2d.c				\
				ft_lstadd_back.c			\
				ft_lstadd_front.c			\
				ft_lstclear.c				\
				ft_lstdelone.c				\
				ft_lstiter.c				\
				ft_lstlast.c				\
				ft_lstmap.c					\
				ft_lstnew.c					\
				ft_lstsize.c

OBJS		=	${SRCS:.c=.o}

all:			${NAME}

${NAME}:		${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
