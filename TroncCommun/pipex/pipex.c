/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:54:25 by julien            #+#    #+#             */
/*   Updated: 2022/09/18 03:03:45 by julien           ###   ########.fr       */
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

void	ft_pipex(t_var *pipex, int indexfd, char *order, char *argv)
{
	pipex->pid = ft_fork();
	if (pipex->pid == 0)
	{
		close(pipex->pipe_fd[indexfd]);
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
