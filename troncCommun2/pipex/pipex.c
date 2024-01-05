/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:58:42 by jdetre            #+#    #+#             */
/*   Updated: 2024/01/05 15:49:50 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_var	pipex;
	(void)envp;
	(void)pipex;
	if (argc < 5)
		ft_printf("Pipex: Too few arguments.\n");
	else if (argc > 5)
		ft_printf("Pipex: Too many arguments.\n");
	else
	{
		pipex.infile = open_infile(argv[1]);	
	}
	return (0);
}
