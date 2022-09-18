/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:00:48 by julien            #+#    #+#             */
/*   Updated: 2022/09/18 05:30:40 by julien           ###   ########.fr       */
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
	dup2(fd_in, 0);
	dup2(fd_out, 1);
}

void	ft_choose_dup2(t_var *pipex, char *order)
{
	int	trash;

	if (ft_strncmp(order, "last", 4) == 0)
	{
		if (pipex->outfile == -1)
		{
			trash = open("/dev/null", O_WRONLY );
			pipex->outfile = trash;
		}
		ft_dup2(pipex->pipe_fd[0], pipex->outfile);
	}
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
