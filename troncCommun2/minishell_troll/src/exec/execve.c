/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:18:27 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/26 16:47:45 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_space_in_cmd(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static char	**handle_cmd_with_space(t_line *s_line, char **path)
{
	char	**cmd;

	cmd = ft_tabdup(s_line->tab_a_line[0]);
	cmd[0] = ft_access(path, cmd[0], cmd[1]);
	return (cmd);
}

char	**ft_set_cmd(t_line *s_line, char **path)
{
	if (check_space_in_cmd(s_line->tab_a_line[0][0]))
		return (handle_cmd_with_space(s_line, path));
	else
		return (handle_cmd_without_space(s_line, path));
}

static void	execute_command(char **cmd, t_environment *s_env, t_line *s_line)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
		execve(cmd[0], cmd, s_env->env);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		s_line->exit_code = WEXITSTATUS(status);
}

void	ft_execve(t_line *s_line, t_environment *s_env)
{
	char	**path;
	char	**cmd;

	if (ft_parsing(s_line->a_line) == 1)
		return ;
	path = ft_split(ft_path(s_line, s_env, NULL, 0), ':');
	if (!path)
		return ;
	cmd = ft_set_cmd(s_line, path);
	if (!cmd || cmd[0] == NULL)
	{
		s_line->exit_code = 127;
		ft_free_double_tab(path, 0);
		ft_free_double_tab(cmd, 1);
		return ;
	}
	execute_command(cmd, s_env, s_line);
	ft_free_double_tab(path, 0);
	ft_free_double_tab(cmd, 0);
}
