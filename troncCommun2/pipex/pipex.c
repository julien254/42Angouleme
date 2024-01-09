/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:58:42 by jdetre            #+#    #+#             */
/*   Updated: 2024/01/09 10:42:52 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_execve(t_var *pipex, char **envp, char **argv)
{
	printf("Debut du processus fils\n");
	pipex->infile = open_infile(argv[1]);
	dup2(pipex->infile, 0);
	close(pipex->infile);
	execve("/data/data/com.termux/files/usr/bin/cat", (char *[]){"cat", "-e", NULL}, envp);
	perror("erreur lancement commande tr");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char **envp)
{
	t_var	pipex;
	int		status;
	int		pid;
	if (argc < 5)
		ft_printf("Pipex: Too few arguments.\n");
	else if (argc > 5)
		ft_printf("Pipex: Too many arguments.\n");
	else
	{
		pid = fork();
		if (pid == 0)
			ft_execve(&pipex, envp, argv);
		waitpid(pid, &status, 0);
		printf("fin du processus fil\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
