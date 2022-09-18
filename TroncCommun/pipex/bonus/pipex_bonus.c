/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:54:25 by julien            #+#    #+#             */
/*   Updated: 2022/09/18 04:35:05 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

void	ft_setbuffer(char *buffer)
{
	size_t	i;

	i = 0;
	while (i < 5)
		buffer[i++] = ' ';
	while (i < 10001)
		buffer[i++] = 0;
}

void	print_here_doc(int argc)
{
	int	i;

	ft_printf("\033[1;34m──(\033[0m");
	if (argc > 6)
	{
		i = 5;
		while(i++ != argc - 1)
			ft_printf("\033[1;32mpipe \033[0m");
	}
	ft_printf("\033[1;32mpipe \033[0m");
	ft_printf("\033[1;32mheredoc\033[0m");
	ft_printf("\033[1;34m)── \033[0m");
}

void	ft_read_stdin(t_var *pipex, char *buffer, char **argv, int argc)
{
	int		ret;
	char	*buffertmp;
	char	*delimiter;
	char	*dest;

	ft_setbuffer(buffer);
	delimiter = ft_strjoin(argv[2], "\n");
	dest = (char*)ft_calloc(sizeof(char) * 1, 1);
	while (strncmp(delimiter, buffer, (ft_strlen(argv[2]) + 1)) != 0)
	{
		print_here_doc(argc);
		ret = read(0, buffer, 10000);
		buffer[ret] = 0;
		if (strncmp(delimiter, buffer, (ft_strlen(argv[2]) + 1)) == 0)
			break;
		buffertmp = ft_strmcpy(buffer);
		dest = ft_strjoin_malloc(dest, buffertmp);
	}
	free(delimiter);
	pipex->input = dest;
}


char	**ft_here_doc(t_var *pipex, char **argv, int *argc)
{
	char	buffer[10001];

	if (strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_read_stdin(pipex,buffer, argv, *argc);
		pipex->argV = argv + 1;
		pipex->argC = *argc - 1;
	}
	else
	{
		pipex->infile = open_infile(argv[1]);
		pipex->argV = argv;
		pipex->argC = *argc;
	}
	return (argv);
}

void	ft_write_fd(t_var *pipex)
{
	if (pipex->infile < 1)
	{
		pipe(pipex->pipe_fd);
		if (pipex->infile == 0)
		{
			write(pipex->pipe_fd[1], pipex->input, ft_strlen(pipex->input));
			free(pipex->input);
		}
		close(pipex->pipe_fd[1]);
		pipex->infile = pipex->pipe_fd[0];
	}
}

void	ft_pipex_loop(t_var *pipex)
{
	ft_pipe(pipex);
	if (pipex->i == pipex->argC - 2)
		ft_pipex_bonus(pipex, "last", pipex->argV[pipex->i]);
	else
		ft_pipex_bonus(pipex, "first", pipex->argV[pipex->i]);
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
	if (argc >= 5)
	{
		pipex.infile = 0;
		ft_here_doc(&pipex, argv, &argc);
		pipex.envp = envp;
		pipex.outfile = open_outfile_bonus(&pipex, pipex.argV[pipex.argC - 1]);
		pipex.i = 2;
		ft_write_fd(&pipex);
		while (pipex.i != pipex.argC - 1)
			ft_pipex_loop(&pipex);
		close(pipex.infile);
		close(pipex.outfile);
	}
	exit(EXIT_SUCCESS);
}
