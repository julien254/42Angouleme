/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:32:52 by judetre           #+#    #+#             */
/*   Updated: 2024/01/25 13:32:56 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_recovery_cmd(t_var *pipex)
{
	size_t		i;
	char		**env;
	char		*test;
	char		*cmd;

	env = pipex->envp;
	while (strncmp(*env, "PATH", 4))
	{
		env++;
		if (*env == NULL)
			return (NULL);
	}
	*env = *env + 5;
	pipex->path = ft_split(*env, ':');
	i = 0;
	while (pipex->path[i])
	{
		test = ft_strjoin(pipex->path[i++], "/");
		cmd = ft_strjoin(test, *pipex->cmd_arg);
		free(test);
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		free(cmd);
	}
	return (NULL);
}

void	ft_if_no_infile(t_var *pipex)
{
	if (pipex->infile == -1)
	{
		pipe(pipex->pipe_fd);
		close(pipex->pipe_fd[1]);
		pipex->infile = pipex->pipe_fd[0];
	}
}

void	ft_pipex(t_var *pipex, char *order, char *argv)
{
	pipex->pid = ft_fork();
	if (pipex->pid == 0)
	{
		if (strncmp(order, "last", 4) == 0)
			close(pipex->pipe_fd[1]);
		else if (strncmp(order, "first", 4) == 0)
			close(pipex->pipe_fd[0]);
		ft_choose_dup2(pipex, order);
		ft_execve(pipex, argv);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_var	pipex;

	if (argc < 5)
		ft_printf("Pipex: Too few arguments.\n");
	else if (argc > 5)
		ft_printf("Pipex: Too many arguments.\n");
	if (argc == 5)
	{
		pipex.envp = envp;
		pipex.path = 0;
		pipex.infile = open_infile(argv[1]);
		ft_if_no_infile(&pipex);
		pipex.outfile = open_outfile(argv[argc - 1]);
		ft_pipe(&pipex);
		ft_pipex(&pipex, "first", argv[2]);
		ft_pipex(&pipex, "last", argv[3]);
		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);
		waitpid(pipex.pid, NULL, 0);
		close(pipex.infile);
		close(pipex.outfile);
	}
	exit(EXIT_SUCCESS);
}
