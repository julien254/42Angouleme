/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:54:25 by julien            #+#    #+#             */
/*   Updated: 2024/01/25 11:57:14 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_recovery_cmd(t_var *pipex)
{
	size_t	i;
	char	**env;
	char	*test;
	char	*cmd;

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

void	ft_pipex_bonus(t_var *pipex, char *order, char *argv)
{
	pipex->pid = ft_fork();
	if (pipex->pid == 0)
	{
		if (strncmp(order, "last", 4) == 0 && pipex->outfile != -1)
			close(pipex->pipe_fd[1]);
		close(pipex->pipe_fd[0]);
		ft_choose_dup2(pipex, order);
		ft_execve(pipex, argv);
		exit(EXIT_FAILURE);
	}
}

void	ft_pipex_loop(t_var *pipex)
{
	ft_pipe(pipex);
	if (pipex->i == pipex->argc - 2)
		ft_pipex_bonus(pipex, "last", pipex->argv[pipex->i]);
	else
		ft_pipex_bonus(pipex, "first", pipex->argv[pipex->i]);
	close(pipex->infile);
	pipex->infile = pipex->pipe_fd[0];
	close(pipex->pipe_fd[1]);
	waitpid(pipex->pid, NULL, 0);
	pipex->i++;
}

int	main(int argc, char *argv[], char **envp)
{
	t_var	pipex;

	if (argc < 5)
		ft_printf("Pipex: Too few arguments.\n");
	if (strncmp(argv[1], "here_doc", 8) == 0 && argc < 6)
		ft_printf("Pipex: Too few arguments.\n");
	else if (argc >= 5)
	{
		pipex.infile = 0;
		pipex.path = 0;
		ft_here_doc(&pipex, argv, &argc);
		pipex.envp = envp;
		pipex.outfile = open_outfile_bonus(&pipex, pipex.argv[pipex.argc - 1]);
		pipex.i = 2;
		ft_write_fd(&pipex);
		while (pipex.i != pipex.argc - 1)
			ft_pipex_loop(&pipex);
		close(pipex.infile);
		close(pipex.outfile);
	}
	exit(EXIT_SUCCESS);
}
