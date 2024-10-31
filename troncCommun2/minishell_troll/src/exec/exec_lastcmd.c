/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lastcmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:56:18 by gcannaud          #+#    #+#             */
/*   Updated: 2024/08/14 12:56:19 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"	

static void	handle_child_process_lastcmd(t_redirect *s_redirect, t_line *s_line,
			t_environment *s_env)
{
	if (s_redirect->fd_in == STDIN_FILENO && s_redirect->i != 0)
		dup2(s_redirect->pipefd[0], STDIN_FILENO);
	else
		dup2(s_redirect->fd_in, STDIN_FILENO);
	if (s_redirect->fd_out != STDOUT_FILENO
		|| s_redirect->fd_redirect != STDOUT_FILENO)
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

static void	handle_parent_process_lastcmd(t_line *s_line)
{
	int		status;
	pid_t	pid;

	status = 0;
	pid = waitpid(-1, &status, 0);
	while (pid != -1)
	{
		if (WIFEXITED(status))
			s_line->exit_code = WEXITSTATUS(status);
		pid = waitpid(-1, &status, 0);
	}
}

static void	cleanup_lastcmd(t_redirect *s_redirect)
{
	if (s_redirect->fd_here_on == 1)
	{
		close(s_redirect->fd_in);
		if (unlink(s_redirect->fd_name) != 0)
			return ;
		s_redirect->fd_here_on = 0;
	}
}

void	ft_lastcmd(t_redirect *s_redirect, t_line *s_line, t_environment *s_env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_fork_error(s_line, s_env, s_redirect);
	if (pid == 0)
		handle_child_process_lastcmd(s_redirect, s_line, s_env);
	cleanup_lastcmd(s_redirect);
	ft_free_child(s_redirect, s_line, s_env, 0);
	handle_parent_process_lastcmd(s_line);
}
