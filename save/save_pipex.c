/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:54:25 by julien            #+#    #+#             */
/*   Updated: 2022/09/16 11:43:06 by julien           ###   ########.fr       */
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

pid_t	ft_fork()
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
	if (ft_strncmp(order , "first", 4) == 0)
		ft_dup2(pipex->infile, pipex->pipe_fd[1]);
	else
		ft_dup2(pipex->pipe_fd[0], pipex->outfile);
}

int	open_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("Infile");
	return (fd);
}

int	open_outfile(char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0000644);
	if (fd == -1)
	{
		perror("Outfile");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	*ft_recovery_cmd(t_var *pipex)
{
	char	**env;
	char	**path;
	char	*test;
	char	*cmd;

	env = pipex->envp;
	while (strncmp(*env , "PATH", 4))
	{
		env++;
	}
	*env = *env + 5;
	path = ft_split(*env, ':');
	while (*path)
	{
		test = ft_strjoin(*path, "/");
		cmd = ft_strjoin(test, *pipex->cmd_arg);
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		path++;
	}
	return (NULL);
}

void	ft_execve(t_var *pipex, char *argv)
{
	pipex->cmd_arg = ft_split(argv, ' ');
	pipex->cmd = ft_recovery_cmd(pipex);
	if (!pipex->cmd)
	{
		if (pipex->infile == -1 && pipex->outfile == -1)
		{
			ft_putstr_fd(*pipex->cmd_arg, 2);
			ft_putstr_fd(": Command not found.\n", 2);
		}
		exit(EXIT_FAILURE);

	}
	execve(pipex->cmd, pipex->cmd_arg, pipex->envp);
}

void	ft_pipex(t_var *pipex, int indexfd, char *order, char *argv)
{
	pipex->pid = ft_fork();
	if (pipex->pid == 0)
	{
		close(pipex->pipe_fd[indexfd]);
		ft_choose_dup2(pipex, order);
		ft_execve(pipex , argv);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_var	pipex;

	if (argc == 5)
	{
		pipex.envp = envp;
		pipex.infile = open_infile(argv[1]);
		pipex.outfile = open_outfile(argv[argc - 1]);
		ft_pipe(&pipex);
		ft_pipex(&pipex, 0, "first", argv[2]);
		ft_pipex(&pipex, 1, "last", argv[3]);
		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);
		waitpid(pipex.pid, NULL, 0);
		close(pipex.infile);
		close(pipex.outfile);
	}
	exit(EXIT_SUCCESS);
}
