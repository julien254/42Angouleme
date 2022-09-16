/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:30:01 by julien            #+#    #+#             */
/*   Updated: 2022/09/14 20:22:52 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"
#include <sys/stat.h>
#include <fcntl.h>
# define color(color) '"\033["color"m"'

typedef struct s_var
{
	pid_t	pid;
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	char	*cmd;
	char	**cmd_arg;
	char	**envp;
}				t_var;

#endif /* ifndef PIPEX_H */
