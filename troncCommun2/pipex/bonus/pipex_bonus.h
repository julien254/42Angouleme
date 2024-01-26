/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:30:01 by julien            #+#    #+#             */
/*   Updated: 2024/01/25 10:14:31 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_var
{
	pid_t	pid;
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	int		here_doc;
	int		argc;
	int		i;
	char	*cmd;
	char	**cmd_arg;
	char	**envp;
	char	**path;
	char	**argv;
	char	*input;
}				t_var;

void	ft_pipe(t_var *pipex);
pid_t	ft_fork(void);
void	ft_dup2(int fd_in, int fd_out);
void	ft_choose_dup2(t_var *pipex, char *order);
void	ft_execve(t_var *pipex, char *argv);
void	ft_free(t_var *pipex, int option);
int		open_infile(char *file);
int		open_outfile(char *file);
int		open_outfile_bonus(t_var *pipex, char *file);
char	*ft_recovery_cmd(t_var *pipex);
void	ft_pipex(t_var *pipex, char *order, char *argv);
void	ft_pipex_bonus(t_var *pipex, char *order, char *argv);
void	ft_setbuffer(char *buffer);
void	print_here_doc(int argc);
void	ft_read_stdin(t_var *pipex, char *buffer, char **argv, int argc);
void	ft_write_fd(t_var *pipex);
void	ft_here_doc(t_var *pipex, char **argv, int *argc);
char	**ft_split_pipex(const char *s, char c);
#endif /* ifndef PIPEX_H */
