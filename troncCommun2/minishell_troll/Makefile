# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 17:09:40 by uguidoni          #+#    #+#              #
#    Updated: 2024/07/17 18:07:29 by uguidoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := src/main.c \
		src/built-ins/cd.c \
		src/built-ins/env.c \
		src/built-ins/export.c \
		src/built-ins/exit.c \
		src/built-ins/exit_pipe.c \
		src/built-ins/put_export.c \
		src/built-ins/put_export2.c \
		src/built-ins/put_env.c \
		src/built-ins/echo.c \
		src/built-ins/unset.c \
		src/built-ins/sort.c \
		src/built-ins/sort2.c \
		src/exec/execve_function.c \
		src/exec/execve_utils.c \
		src/exec/execve.c \
		src/exec/exec_utils.c \
		src/exec/exec_lastcmd.c \
		src/exec/exec_cmd.c \
		src/exec/exec.c \
		src/exec/exec_error.c \
		src/exec/redirection/exec_pipe.c \
		src/exec/redirection/exec_redirect.c \
		src/set/set_tab.c \
		src/set/set_tab2.c \
		src/set/set_tab3.c \
		src/set/set_tab4.c \
		src/set/handles/handles.c \
		src/set/handles/handles_quote.c \
		src/set/handles/handles_str_utils.c \
		src/set/handles/handles_utils.c \
		src/set/handles/handles_fork.c \
		src/set/handles/handles_fork_utils.c \
		src/set/handles/handles_split.c \
		src/set/handles/handles_split_utils.c \
		src/set/handles/heredoc.c \
		src/set/handles/heredoc_utils.c \
		src/utils/utils.c \
		src/utils/utils2.c \
		src/utils/utils3.c \
		src/utils/signal.c \
		src/utils/free.c \
		src/utils/free2.c \
		src/utils/malloc_protection.c \
		src/utils/other_protections.c \

NAME := minishell

OBJS := $(SRCS:.c=.o)

CFLAGS := -g -Wall -Werror -Wextra -lreadline -Wno-unused-command-line-argument

LIB := libft.a
LIB_TARGET := ./libft/libft.a

HIDE := > /dev/null

%.o: %.c 
	clang $(CFLAGS) -o $@ -c $< $(HEADERS)

all: libft $(NAME)

$(LIB_TARGET):
	@make -C libft $(HIDE)
	@echo "Libft compiled"

libft: $(LIB_TARGET) 

$(NAME): $(OBJS)
	@clang $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft $(HIDE)

clean:
	@make -C libft clean $(HIDE)
	@echo "Libft cleaned"
	rm -f $(OBJS)
	
fclean:
	@make -C libft fclean $(HIDE)
	@echo "Libft cleaned"
	rm -f $(OBJS)
	rm -rf $(NAME)

re: fclean all

.PHONY: %.o all libft clean fclean re
