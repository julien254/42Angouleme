/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:58:42 by jdetre            #+#    #+#             */
/*   Updated: 2024/01/20 12:32:26 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	search_quote(int *i, char *str)
{
	*i = *i + 1;
	while (str[*i] != '\'')
        *i = *i + 1;	
    *i = *i + 1;	
}
int	count_word(const char *str, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (str[i++] != sep)
		count++;
	while (str[i])
	{
		if (str[i] != sep && str[i - 1] == sep)
		{
			if (str[i] == '\'')
			{	
				i++;
				while (str[i] != '\'')
					i++;

			}
			count++;
		}
		i++;
	}
	return (count);
}

char	*substr(const char *str, int start, int end)
{
	int		size;
	char	*substr;
	int		i;

	size = (end - start) + 1;
	substr = (char *)malloc((size + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	if (str[start] == '\'' && str[end] == '\'')
	{
		start++;
		end--;
	}
	while (start <= end)
	{
		substr[i] = str[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_split_pipex(const char *s, char c)
{
	int		start;
	int		i;
	int		j;
	char	**split;

	split = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			
			start = i;
			if (s[i] == '\'')
				search_quote(&i, (char *)s);
			else
			{
				while (s[i] != c && s[i])
				i++;
			}
			split[j++] = substr(s, start, i - 1);
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}
void ft_pipe(t_var *pipex)
{
    if (pipe(pipex->pipe) == -1)
    {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
}

void ft_dup2(int new_stdin, int new_stdout)
{
    dup2(new_stdin, 0);
    dup2(new_stdout, 1);
}

char *recover_command(t_var *pipex)
{
    char **env;
    char *cmd_temp;
    char *cmd;
    int i;

    env = pipex->envp;
    while (ft_strncmp(*env, "PATH", 4))
    {
        env++;
        if (*env == NULL)
            return (NULL);
    }
    *env = *env + 5;
    pipex->path = ft_split(*env, ':');
    i = 0;
    while (pipex->path[i])
    {
        cmd_temp = ft_strjoin(pipex->path[i++], "/");
        cmd = ft_strjoin(cmd_temp, *pipex->cmd_arg);
        free(cmd_temp);
        if (access(cmd, F_OK | X_OK) == 0)
            return (cmd);
        free(cmd);
    }
    return (NULL);
}

char **ft_recover_cmd_args(t_var *pipex, char *argv)
{
    pipex->cmd_arg = ft_split_pipex(argv, ' ');
    if (!pipex->cmd_arg)
    {
        ft_putstr_fd("Pipex: command not found.", 2);
        exit(EXIT_FAILURE);
    }
    return (pipex->cmd_arg);
}

void first_child(t_var *pipex)
{
    char *cmd;

    ft_dup2(pipex->infile, pipex->pipe[1]);
    close(pipex->infile);
    close(pipex->pipe[0]);
    ft_recover_cmd_args(pipex, pipex->argv[2]);
    cmd = recover_command(pipex);
    execve(cmd, pipex->cmd_arg, pipex->envp);
    perror("Execve");
    exit(EXIT_FAILURE);
}

void last_child(t_var *pipex)
{
    char *cmd;

    ft_dup2(pipex->pipe[0], pipex->outfile);
    close(pipex->pipe[1]);
    ft_recover_cmd_args(pipex, pipex->argv[3]);
    cmd = recover_command(pipex);
    execve(cmd, pipex->cmd_arg, pipex->envp);
    perror("Execve");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[], char **envp)
{
    t_var pipex;
    int status;
    int pid;
    int pid2;

    if (argc < 5)
    {
        ft_printf("Pipex: Too few arguments.\n");
        exit(EXIT_FAILURE);
    }
    else if (argc > 5)
    {
        ft_printf("Pipex: Too many arguments.\n");
        exit(EXIT_FAILURE);
    }
    pipex.envp = envp;
    pipex.argc = argc;
    pipex.argv = argv;
    pipex.infile = open_infile(pipex.argv[1]);
    pipex.outfile = open_outfile(pipex.argv[pipex.argc - 1]);
    ft_pipe(&pipex);
    pid = fork();
    if (pid == 0)
        first_child(&pipex);
    pid2 = fork();
    if (pid2 == 0)
        last_child(&pipex);
    close(pipex.pipe[0]);
    close(pipex.pipe[1]);
    waitpid(pid, &status, 0);
    waitpid(pid2, &status, 0);
    exit(EXIT_SUCCESS);
}

