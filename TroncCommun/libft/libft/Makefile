# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:28:17 by julien            #+#    #+#              #
#    Updated: 2022/04/25 16:45:24 by jdetre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc -g

CFLAGS		= -Wall -Wextra -Werror -I.

SRCS		=   ft_atoi.c       \
				ft_bzero.c      \
				ft_calloc.c     \
				ft_isalnum.c    \
				ft_isalpha.c    \
				ft_isascii.c    \
				ft_isdigit.c    \
				ft_isprint.c    \
				ft_itoa.c       \
				ft_memchr.c     \
				ft_memcmp.c     \
				ft_memcpy.c     \
				ft_memmove.c    \
				ft_memset.c     \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c  \
				ft_putstr_fd.c  \
				ft_split.c      \
				ft_strchr.c     \
				ft_strdup.c     \
				ft_striteri.c   \
				ft_strjoin.c    \
				ft_strlcat.c    \
				ft_strlcpy.c    \
				ft_strlen.c     \
				ft_strmapi.c    \
				ft_strncmp.c    \
				ft_strnstr.c    \
				ft_strrchr.c    \
				ft_strtrim.c    \
				ft_substr.c     \
				ft_tolower.c    \
				ft_toupper.c

BONUS		=   ft_lstadd_back.c \
				ft_lstadd_front.c\
				ft_lstclear.c    \
				ft_lstdelone.c   \
				ft_lstiter.c     \
				ft_lstlast.c     \
				ft_lstmap.c      \
				ft_lstnew.c      \
				ft_lstsize.c     \

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${BONUS:.c=.o}



all:		${NAME}

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus:		${OBJS} ${OBJS_BONUS}
	ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJS_BONUS)

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
