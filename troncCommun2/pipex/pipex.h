/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:35:32 by judetre           #+#    #+#             */
/*   Updated: 2024/01/09 10:32:13 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef	struct s_var
{
	pid_t	pid;
	int		pipe[2];
	int		infile;
	int 	outfile;
	char	*cmd;
	char	**cmd_arg;
	char	**envp;
	char 	**path;
}			t_var;

int	open_infile(char *file);

#endif
