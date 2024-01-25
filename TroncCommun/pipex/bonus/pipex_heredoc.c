/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:00:24 by julien            #+#    #+#             */
/*   Updated: 2024/01/21 07:42:36 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
		while (i++ != argc - 1)
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
	dest = (char *)ft_calloc(sizeof(char) * 1, 1);
	while (strncmp(delimiter, buffer, (ft_strlen(argv[2]) + 1)) != 0)
	{
		print_here_doc(argc);
		ret = read(0, buffer, 10000);
		buffer[ret] = 0;
		if (strncmp(delimiter, buffer, (ft_strlen(argv[2]) + 1)) == 0)
			break ;
		buffertmp = ft_strdup(buffer);
		dest = ft_strjoin_malloc(dest, buffertmp);
	}
	free(delimiter);
	pipex->input = dest;
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

void	ft_here_doc(t_var *pipex, char **argv, int *argc)
{
	char	buffer[10001];

	if (strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_read_stdin(pipex, buffer, argv, *argc);
		pipex->argv = argv + 1;
		pipex->argc = *argc - 1;
	}
	else
	{
		pipex->infile = open_infile(argv[1]);
		pipex->argv = argv;
		pipex->argc = *argc;
	}
}
