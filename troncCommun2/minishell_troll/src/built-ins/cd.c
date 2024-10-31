/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:54:15 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/26 17:59:29 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_cd_pipe(char *a_line, t_line *s_line, t_environment *s_env,
	t_redirect *s_redirect)
{
	char		**arg;
	int			i;

	arg = ft_split(a_line, ' ');
	if (!arg)
		ft_malloc_error(s_line, s_env, s_redirect);
	i = 0;
	while (arg[i] != 0)
		i++;
	s_line->exit_code = 1;
	if (i > 2)
		write(2, "bash: cd: too many arguments\n", 29);
	else if (i != 1 && access(arg[1], F_OK | X_OK) != 0)
	{
		write(2, "bash: cd: ", 10);
		perror(arg[1]);
	}
	else
		s_line->exit_code = 0;
	i = 0;
	while (arg[i] != 0)
		free(arg[i++]);
	free(arg);
}

void	ft_actualise_pwd(t_environment *s_env, char *var, t_line *s_line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s_env->env[i] != 0
		&& ft_strncmp(s_env->env[i], var, 4) != 0)
		i++;
	if (s_env->env[i] == 0)
		return ;
	free(s_env->env[i]);
	tmp = getcwd(0, 0);
	s_env->env[i] = ft_strjoin(var, tmp);
	free(tmp);
	if (!s_env->env[i])
		ft_malloc_error(s_line, s_env, NULL);
	i = 0;
	while (s_env->export[i] != 0
		&& ft_strncmp(s_env->export[i], var, 4) != 0)
		i++;
	free(s_env->export[i]);
	tmp = getcwd(0, 0);
	s_env->export[i] = ft_strjoin(var, tmp);
	free(tmp);
	if (!s_env->export[i])
		ft_malloc_error(s_line, s_env, NULL);
}

void	ft_cd2(char **arg, t_environment *s_env, int i, t_line *s_line)
{
	s_line->getcwd_free = getcwd(0, 0);
	if (i == 1)
	{
		if (ft_getenv("HOME", s_env->env) == NULL)
		{
			printf("bash: cd: HOME not set\n");
			return ;
		}
		if (s_line->getcwd_free != NULL)
		{
			ft_actualise_pwd(s_env, "OLDPWD=", s_line);
			free(s_line->getcwd_free);
		}
		chdir(ft_getenv("HOME", s_env->env));
	}
	else
	{
		if (s_line->getcwd_free != NULL)
		{
			ft_actualise_pwd(s_env, "OLDPWD=", s_line);
			free(s_line->getcwd_free);
		}
		chdir(arg[1]);
	}
	s_line->exit_code = 0;
}

void	ft_cd_error(char **arg, int i, t_environment *s_env, t_line *s_line)
{
	if (i > 2)
		write(2, "bash: cd: too many arguments\n", 29);
	else if (i != 1 && access(arg[1], F_OK | X_OK) != 0)
	{
		write(2, "bash: cd: ", 10);
		perror(arg[1]);
	}
	else
		ft_cd2(arg, s_env, i, s_line);
}

void	ft_cd(t_line *s_line, t_environment *s_env)
{
	char		**arg;
	int			i;

	arg = ft_split(s_line->a_line, ' ');
	if (!arg)
		ft_malloc_error(s_line, s_env, NULL);
	i = 0;
	while (arg[i] != 0)
		i++;
	s_line->exit_code = 1;
	ft_cd_error(arg, i, s_env, s_line);
	i = 0;
	while (arg[i] != 0)
		free(arg[i++]);
	free(arg);
	s_line->getcwd_free = getcwd(0, 0);
	if (s_line->getcwd_free != NULL)
	{
		ft_actualise_pwd(s_env, "PWD=", s_line);
		free(s_line->getcwd_free);
	}
}
