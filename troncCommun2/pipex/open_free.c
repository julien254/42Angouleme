/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:31:00 by judetre           #+#    #+#             */
/*   Updated: 2024/01/25 13:32:01 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(t_var *pipex, int option)
{
	size_t	i;

	i = 0;
	while (pipex->cmd_arg[i])
		free(pipex->cmd_arg[i++]);
	free(pipex->cmd_arg);
	i = 0;
	if (option)
	{
		while (pipex->path[i])
			free(pipex->path[i++]);
		free(pipex->path);
	}
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
		perror("Outfile");
	return (fd);
}
