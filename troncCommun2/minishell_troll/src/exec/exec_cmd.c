/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:55:58 by gcannaud          #+#    #+#             */
/*   Updated: 2024/08/14 12:56:00 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"	

static void	handle_child_process_pipe(t_redirect *s_redirect,
			t_line *s_line, t_environment *s_env)
{
	if (s_redirect->fd_out == STDOUT_FILENO)
	{
		close(s_redirect->pipefd[0]);
		dup2(s_redirect->pipefd[1], s_redirect->fd_redirect);
		close(s_redirect->pipefd[1]);
	}
	else
		dup2(s_redirect->fd_out, s_redirect->fd_redirect);
	if (s_redirect->fd_in != STDIN_FILENO)
		dup2(s_redirect->fd_in, STDIN_FILENO);
	if (s_redirect->fd_redirect != STDOUT_FILENO)
		dup2(s_redirect->fd_out, s_redirect->fd_redirect);
	s_redirect->cmdpath = ft_access_pipe(s_redirect->path,
			s_line->tab_a_line[s_redirect->i][0],
			s_line->tab_a_line[s_redirect->i][1]);
	if (s_redirect->cmdpath != NULL && s_redirect->cmdpath != (void *)1)
	{
		ft_call_funcs_pipe(s_redirect, s_line, s_env);
		ft_free_child(s_redirect, s_line, s_env, 1);
		exit(0);
	}
	ft_free_child(s_redirect, s_line, s_env, 1);
	if (s_redirect->cmdpath == (void *)1)
		exit(0);
	exit(127);
}

static void	handle_parent_process_pipe(t_redirect *s_redirect)
{
	s_redirect->fd_redirect = 1;
	s_redirect->fd_out = 1;
	if (s_redirect->fd_here_on == 1)
	{
		close(s_redirect->fd_in);
		if (unlink(s_redirect->fd_name) != 0)
			return ;
		s_redirect->fd_in = open(ft_fd_load(), O_RDONLY);
		s_redirect->fd_here_on = 0;
	}
	else
		s_redirect->fd_in = 0;
	if (s_redirect->fd_out == STDOUT_FILENO)
	{
		close(s_redirect->pipefd[1]);
		dup2(s_redirect->pipefd[0], STDIN_FILENO);
	}
}

static void	setup_pipe(t_redirect *s_redirect, t_line *s_line,
			t_environment *s_env)
{
	if (s_redirect->pipefd[0] && s_redirect->pipefd[0] != 0)
		close(s_redirect->pipefd[0]);
	if (s_redirect->fd_out == STDOUT_FILENO)
	{
		if (pipe(s_redirect->pipefd) == -1)
			ft_pipe_error(s_line, s_env, s_redirect);
	}
}

void	ft_pipe(t_redirect *s_redirect, t_line *s_line, t_environment *s_env)
{
	pid_t	pid;

	setup_pipe(s_redirect, s_line, s_env);
	pid = fork();
	if (pid == -1)
		ft_fork_error(s_line, s_env, s_redirect);
	if (pid == 0)
		handle_child_process_pipe(s_redirect, s_line, s_env);
	handle_parent_process_pipe(s_redirect);
}
