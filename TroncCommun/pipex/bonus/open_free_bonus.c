/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_free_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:06:27 by julien            #+#    #+#             */
/*   Updated: 2024/01/21 07:35:38 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

int	open_outfile_bonus(t_var *pipex, char *file)
{
	int	fd;

	if (pipex->infile)
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0000644);
	else
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0000644);
	if (fd == -1)
		perror("Outfile");
	return (fd);
}
