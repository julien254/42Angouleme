/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:08:08 by gcannaud          #+#    #+#             */
/*   Updated: 2024/08/14 13:08:09 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_print_error(char *cmd)
{
	if (cmd && cmd[0])
		ft_putstr_fd(cmd, 2);
	else
		write(2, "''", 2);
	write(2, ": command not found\n", 20);
	free(cmd);
}

char	*ft_access(char **path, char *cmd, char *cmd_next)
{
	int		i;
	char	*temp;
	char	*verif;

	i = 0;
	if (cmd && cmd[0] && ft_point_error(cmd, cmd_next) == 1)
		return (NULL);
	while (cmd && cmd[0] && path[i] != 0)
	{
		temp = ft_strjoin(path[i], "/");
		verif = ft_strjoin(temp, cmd);
		free(temp);
		if ((access(verif, F_OK) == 0) && (access(verif, X_OK) == 0))
		{
			free(cmd);
			return (verif);
		}
		free(verif);
		i++;
	}
	ft_print_error(cmd);
	return (NULL);
}

void	ft_free_double_tab(char **tab, int i)
{
	if (!tab || !tab[i])
		return ;
	while (tab[i] && tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_check_builtin(char *tmp)
{
	return (ft_strncmp(tmp, "export", 7) != 0
		&& ft_strncmp(tmp, "cd", 3) != 0
		&& ft_strncmp(tmp, "exit", 5) != 0
		&& ft_strncmp(tmp, "unset", 6) != 0
		&& ft_strncmp(tmp, "pwd", 4) != 0
		&& ft_strncmp(tmp, "env", 4) != 0
		&& ft_strncmp(tmp, "echo", 5) != 0);
}

char	**handle_cmd_without_space(t_line *s_line, char **path)
{
	char	**cmd;

	cmd = ft_split(s_line->a_line, ' ');
	if (cmd[0] != NULL && ft_strchr(cmd[0], '/') != 0)
	{
		cmd[0] = ft_executable(cmd[0]);
		ft_free_env2(cmd);
		cmd = ft_split(s_line->a_line, ' ');
	}
	else
	{
		ft_free_env2(cmd);
		cmd = ft_handles_split(s_line->a_line, ' ');
		cmd[0] = ft_access(path, cmd[0], cmd[1]);
	}
	return (cmd);
}
