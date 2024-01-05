/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:35:32 by judetre           #+#    #+#             */
/*   Updated: 2024/01/05 10:50:54 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
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
