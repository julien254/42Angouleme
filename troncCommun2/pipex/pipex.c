/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:58:42 by jdetre            #+#    #+#             */
/*   Updated: 2024/01/09 22:03:23 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
char	*recover_command(t_var *pipex)
{
	char	**env;
	char	*cmd_temp;
	char 	*cmd;
	int		i;

	env = pipex->envp;
	while (ft_strncmp(*env, "PATH", 4))
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
		cmd_temp = ft_strjoin(pipex->path[i++], "/");

		cmd = ft_strjoin(cmd_temp, *pipex->cmd_arg);
		free(cmd_temp);
		if (access(cmd, F_OK | X_OK))
			return (cmd);
		free(cmd);
	}
	return (NULL);
}
char	**ft_recover_cmd_args(t_var *pipex, char *argv)
{

	pipex->cmd_arg = ft_split(argv, ' ');
	if (!pipex->cmd_arg)
	{
		ft_putstr_fd("Pipex: command not found.", 2);
		exit(EXIT_FAILURE);
	}
	return (pipex->cmd_arg);
}
void	first_child(t_var *pipex, char **envp, char **argv)
{
	char	*cmd;

	ft_printf("Debut du processus fils 1\n");
	pipex->infile = open_infile(argv[1]);
	dup2(pipex->infile, 0);
	dup2(pipex->pipe[1], 1);
	close(pipex->infile);
	close(pipex->pipe[0]);
	ft_recover_cmd_args(pipex, argv[1]);
	cmd = recover_command(pipex);
	execve(cmd, pipex->cmd_arg, envp);
	perror("erreur lancement commande cat");
	exit(EXIT_FAILURE);
}

void	last_child(t_var *pipex, char **envp, char **argv)
{
	char	*cmd;

	ft_printf("Debut du processus fils 2\n");
	pipex->outfile = open_outfile(argv[pipex->argc - 1]);
	dup2(pipex->pipe[0], 0);
	dup2(pipex->outfile, 1);
	close(pipex->pipe[1]);
	ft_recover_cmd_args(pipex, argv[2]);
	cmd = recover_command(pipex);
	execve(cmd, pipex->cmd_arg, envp);
	perror("erreur lancement commande xargs");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char **envp)
{
	t_var	pipex;
	int		status;
	int		pid;
	int		pid2;

	if (argc < 5)
		ft_printf("Pipex: Too few arguments.\n");
	else if (argc > 5)
		ft_printf("Pipex: Too many arguments.\n");
	else
	{
		pipex.envp = envp;
		pipex.argc = argc;
		pipe(pipex.pipe);
		pid = fork();
		if (pid == 0)
			first_child(&pipex, envp, argv);
		pid2 = fork();
		if (pid2 == 0)
			last_child(&pipex, envp, argv);
		close(pipex.pipe[0]);
		close(pipex.pipe[1]);
		waitpid(pid, &status, 0);
		ft_printf("fin du processus fil1\n");
		waitpid(pid2, &status, 0);
		ft_printf("fin du processus fil2\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
