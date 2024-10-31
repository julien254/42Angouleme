/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:39:29 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/26 18:14:45 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void	handle_builtin_commands(t_redirect *s_redirect, t_line *s_line,
			t_environment *s_env)
{
	if (is_builtin_command(s_line->tab_a_line[s_redirect->i][0], "echo"))
		ft_echo(s_line->a_line2, s_line);
	else if (is_builtin_command(s_line->tab_a_line[s_redirect->i][0], "env"))
		ft_env(s_env->env, s_line->a_line2, s_line);
	else if (is_builtin_command(s_line->tab_a_line[s_redirect->i][0], "pwd"))
	{
		ft_printf("%s\n", ft_getenv("PWD", s_env->env));
		s_line->exit_code = 0;
	}
	else if (is_builtin_command(s_line->tab_a_line[s_redirect->i][0],
		"export"))
		ft_export_pipe(s_line->a_line2, s_env, s_line, s_redirect);
	else if (is_builtin_command(s_line->tab_a_line[s_redirect->i][0], "cd"))
		ft_cd_pipe(s_line->a_line2, s_line, s_env, s_redirect);
	else if (is_builtin_command(s_line->tab_a_line[s_redirect->i][0], "exit"))
		s_line->exit_code = ft_exit_pipe(s_line, s_env, s_redirect);
}

char	*handle_no_path(char *cmd, char *cmd_next)
{
	if (cmd[0] != '\0' && ft_point_error(cmd, cmd_next) == 1)
		return (NULL);
	if (ft_strchr(cmd, '/') != 0)
		return (ft_executable(cmd));
	write(2, "minishell: ", 11);
	ft_putstr_fd(cmd, 2);
	write(2, ": No such file or directory\n", 28);
	exit(1);
}

int	is_builtin_command_lst(char *cmd)
{
	int	result;

	result = (ft_strncmp(cmd, "export", 7) == 0);
	if (!result)
		result = (ft_strncmp(cmd, "cd", 3) == 0);
	if (!result)
		result = (ft_strncmp(cmd, "exit", 5) == 0);
	if (!result)
		result = (ft_strncmp(cmd, "unset", 6) == 0);
	if (!result)
		result = (ft_strncmp(cmd, "pwd", 4) == 0);
	if (!result)
		result = (ft_strncmp(cmd, "env", 4) == 0);
	if (!result)
		result = (ft_strncmp(cmd, "echo", 5) == 0);
	return (result);
}

char	*check_access(char **path, char *cmd)
{
	int		i;
	char	*temp;
	char	*verif;

	i = 0;
	while (path[i] != 0)
	{
		temp = ft_strjoin(path[i], "/");
		verif = ft_strjoin(temp, cmd);
		free(temp);
		if (is_builtin_command_lst(cmd) || (access(verif, F_OK) == 0
				&& access(verif, X_OK) == 0))
			return (verif);
		free(verif);
		i++;
	}
	return (NULL);
}

char	*ft_access_pipe(char **path, char *cmd, char *cmd_next)
{
	char	*result;

	if (!path)
		return (handle_no_path(cmd, cmd_next));
	result = check_access(path, cmd);
	if (result)
		return (result);
	if (ft_strchr(cmd, '/') != 0)
		return (ft_executable(cmd));
	if (ft_strcmp(cmd, "<<") == 0)
		return ((char *)1);
	if (cmd[0] != '\0')
		ft_putstr_fd(cmd, 2);
	else
		write(2, "''", 2);
	write(2, ": command not found\n", 20);
	return (NULL);
}
