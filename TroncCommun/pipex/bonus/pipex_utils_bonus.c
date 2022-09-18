/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:00:48 by julien            #+#    #+#             */
/*   Updated: 2022/09/18 02:58:15 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe(t_var *pipex)
{
	if (pipe(pipex->pipe_fd) == -1)
	{
		perror("Pipe");
		exit(EXIT_FAILURE);
	}
}

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	ft_dup2(int fd_in, int fd_out)
{
	if (dup2(fd_in, 0) == -1)
		perror("dup2");
	if (dup2(fd_out, 1) == -1)
		perror("dup2");
}

void	ft_choose_dup2(t_var *pipex, char *order)
{
		if (ft_strncmp(order, "last", 4) == 0)
			ft_dup2(pipex->infile, pipex->outfile);
		else
			ft_dup2(pipex->infile, pipex->pipe_fd[1]);
}

void	ft_execve(t_var *pipex, char *argv)
{
	pipex->cmd_arg = ft_split(argv, ' ');
	pipex->cmd = ft_recovery_cmd(pipex);
	if (!pipex->cmd)
	{
		ft_putstr_fd("Pipex: Command not found: ", 2);
		ft_putstr_fd(*pipex->cmd_arg, 2);
		ft_putstr_fd("\n", 2);
		ft_free(pipex);
		exit(EXIT_SUCCESS);
	}
	execve(pipex->cmd, pipex->cmd_arg, pipex->envp);
}
