/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:41:20 by uguidoni          #+#    #+#             */
/*   Updated: 2024/06/20 12:40:20 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_add_envvar2_env(char *str, t_environment *s_env, int i)
{
	char	**temp;

	temp = ft_tabcpy(s_env->env, 2);
	if (!temp)
		return (1);
	free(temp[i]);
	temp[i] = ft_cut(str, '+', 0);
	if (!temp[i])
	{
		ft_free_env3(temp);
		return (1);
	}
	ft_free_env2(s_env->env);
	s_env->env = ft_tabcpy(temp, 1);
	ft_free_env2(temp);
	if (!s_env->env)
		return (1);
	return (0);
}

int	ft_add_envvar_env(char *str, t_environment *s_env, int i)
{
	char	**temp;

	temp = ft_tabcpy(s_env->env, 2);
	if (!temp)
		return (1);
	free(temp[i]);
	temp[i] = ft_strdup(str);
	if (!temp[i])
	{
		ft_free_env3(temp);
		return (1);
	}
	ft_free_env2(s_env->env);
	s_env->env = ft_tabcpy(temp, 1);
	ft_free_env2(temp);
	if (!s_env->env)
		return (1);
	return (0);
}

int	ft_join_env(char *str, t_environment *s_env, char *temp)
{
	int	i;

	i = 0;
	while (s_env->env[i] != 0)
	{
		if (ft_strncmp(s_env->env[i], str, ft_lequal2(s_env->export[i])) == 0)
			break ;
		i++;
	}
	if (s_env->env[i] == 0)
	{
		if (ft_add_envvar2_export(str, s_env, i, 1) == 1)
			return (1);
		free(temp);
		return (0);
	}
	s_env->env[i] = ft_strdeljoin(s_env->env[i], temp);
	if (!s_env->env[i])
		return (1);
	return (0);
}

int	ft_putenv(char *str, t_environment *s_env)
{
	int		i;

	if (ft_strchr(str, '=') == 0)
		return (0);
	if (str[ft_lequal2(str)] == '+' && (ft_join_export(str, s_env, 1) == 1))
		return (1);
	else if (str[ft_lequal2(str)] == '+')
		return (0);
	i = 0;
	while (s_env->env[i] != 0)
	{
		if (ft_strncmp(s_env->env[i], str, ft_lequal2(s_env->env[i])) == 0
			&& ft_strncmp(s_env->env[i], str, ft_lequal2(str)) == 0)
		{
			free(s_env->env[i]);
			s_env->env[i] = ft_strdup(str);
			if (!s_env->env[i])
				return (1);
			return (0);
		}
		i++;
	}
	if (ft_add_envvar_export(str, s_env, i, 1) == 1)
		return (1);
	return (0);
}
