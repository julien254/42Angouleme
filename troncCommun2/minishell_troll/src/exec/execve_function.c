/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:34:00 by gcannaud          #+#    #+#             */
/*   Updated: 2024/08/14 13:34:01 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_create_tmp(t_line *s_line, t_environment *s_env,
		t_redirect *s_redirect)
{
	int		i;
	char	*tmp;
	int		j;

	i = ft_lfirstparam(s_line->a_line);
	tmp = ft_calloc(i + 1, sizeof(char));
	if (!tmp)
		ft_malloc_error(s_line, s_env, s_redirect);
	j = 0;
	while (j != i)
	{
		tmp[j] = s_line->a_line[j];
		j++;
	}
	return (tmp);
}

char	*ft_path(t_line *s_line, t_environment *s_env,
	t_redirect *s_redirect, int check)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s_env->env[i] != 0)
	{
		if (ft_strncmp(s_env->env[i], "PATH", 4) == 0)
			return (s_env->env[i]);
		i++;
	}
	tmp = ft_create_tmp(s_line, s_env, s_redirect);
	if (!tmp)
		return (NULL);
	if (((access(tmp, F_OK) != 0) || (access(tmp, X_OK) != 0))
		&& ft_check_builtin(tmp))
	{
		if (check == 0)
			ft_printf("minishell: %s: No such file or directory\n", tmp);
		free(tmp);
		tmp = NULL;
	}
	return (tmp);
}

int	ft_parsing(char *a_line)
{
	size_t	i;

	i = 0;
	while (a_line[i] == '/')
		i++;
	if ((i == ft_strlen(a_line) || (ft_strncmp(a_line, "./", 2) == 0))
		&& (a_line[2] == '\0' || a_line[2] == ' '))
	{
		ft_printf("minishell: %s: Is a directory\n", a_line);
		return (1);
	}
	return (0);
}

char	*ft_executable(char *cmd)
{
	if (access(cmd, F_OK) != 0 || access(cmd, X_OK) != 0)
	{
		ft_printf("minishell: %s: No such file or directory\n", cmd);
		free(cmd);
		cmd = NULL;
	}
	return (cmd);
}
