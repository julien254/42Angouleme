/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:06:27 by julien            #+#    #+#             */
/*   Updated: 2022/09/16 18:18:29 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(t_var *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->cmd_arg[i])
		free(pipex->cmd_arg[i++]);
	free(pipex->cmd_arg);
	i = 0;
	while (pipex->path[i])
		free(pipex->path[i++]);
	free(pipex->path);
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
