/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_export2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:41:38 by uguidoni          #+#    #+#             */
/*   Updated: 2024/06/20 12:47:56 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_add_envvar2_export(char *str, t_environment *s_env, int i, int pass)
{
	char	**temp;

	if (pass == 0)
	{
		temp = ft_tabcpy(s_env->export, 2);
		if (!temp)
			return (1);
		free(temp[i]);
		temp[i] = ft_cut(str, '+', 0);
		if (!temp[i])
		{
			ft_free_env3(temp);
			return (1);
		}
		ft_free_env2(s_env->export);
		s_env->export = ft_tabcpy(temp, 1);
		ft_free_env2(temp);
		if (!s_env->export)
			return (1);
		return (0);
	}
	if (ft_add_envvar2_env(str, s_env, i) == 1)
		return (1);
	return (0);
}

int	ft_join_export2(char *str, t_environment *s_env, char *temp)
{
	int	i;

	i = 0;
	while (s_env->export[i] != 0)
	{
		if (ft_strncmp(s_env->export[i], str,
				ft_lequal2(s_env->export[i])) == 0)
			break ;
		i++;
	}
	if (s_env->export[i] == 0)
	{
		if (ft_add_envvar2_export(str, s_env, i, 0) == 1)
			return (1);
		free(temp);
		return (0);
	}
	s_env->export[i] = ft_strdeljoin(s_env->export[i], temp);
	if (!s_env->export[i])
	{
		free(temp);
		return (1);
	}
	return (0);
}

int	ft_join_export(char *str, t_environment *s_env, int pass)
{
	char	*temp;

	temp = ft_after_equal(str);
	if (!temp)
		return (1);
	if (pass == 0)
	{
		if (ft_join_export2(str, s_env, temp) == 1)
			return (1);
		return (0);
	}
	if (ft_join_env(str, s_env, temp) == 1)
		return (1);
	return (0);
}

int	ft_add_envvar_export(char *str, t_environment *s_env, int i, int pass)
{
	char	**temp;

	if (pass == 0)
	{
		temp = ft_tabcpy(s_env->export, 2);
		if (!temp)
			return (1);
		free(temp[i]);
		temp[i] = ft_strdup(str);
		if (!temp[i])
		{
			ft_free_env3(temp);
			return (1);
		}
		ft_free_env2(s_env->export);
		s_env->export = ft_tabcpy(temp, 1);
		ft_free_env2(temp);
		if (!s_env->export)
			return (1);
		return (0);
	}
	if (ft_add_envvar_env(str, s_env, i) == 1)
		return (1);
	return (0);
}
