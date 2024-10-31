/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:21:58 by uguidoni          #+#    #+#             */
/*   Updated: 2024/06/20 11:45:33 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_unset3(t_environment *s_env, int f, int call, int i)
{
	if (call == 0)
	{
		while (i != f)
			i++;
		free(s_env->env[i]);
		s_env->env[i] = NULL;
		while (s_env->env[f + 1] != 0)
		{
			s_env->env[f] = s_env->env[f + 1];
			f++;
		}
		s_env->env[f] = NULL;
		return ;
	}
	while (i != f)
		i++;
	free(s_env->export[i]);
	s_env->export[i] = NULL;
	while (s_env->export[f + 1] != 0)
	{
		s_env->export[f] = s_env->export[f + 1];
		f++;
	}
	s_env->export[f] = NULL;
}

void	ft_unset2(char **a_line_unset, t_environment *s_env, int i, int x)
{
	int		j;
	int		k;

	j = 1;
	while (s_env->export[j] != 0)
	{
		if (ft_strncmp(s_env->export[j],
				a_line_unset[i], ft_lequal2(s_env->export[j])) == 0)
		{
			if (ft_strlen(a_line_unset[i])
				== (size_t)ft_lequal2(s_env->export[j]))
			{
				k = 0;
				while (s_env->env[k] != 0 && ft_strncmp(s_env->env[k],
						s_env->export[j], ft_strlen(s_env->env[k])) != 0)
					k++;
				if (s_env->env[k] != 0 && ft_strncmp(s_env->env[k],
						s_env->export[j], ft_strlen(s_env->env[k])) == 0)
					ft_unset3(s_env, k, 0, x);
				ft_unset3(s_env, j, 1, x);
			}
		}
		j++;
	}
}

void	ft_unset(char *a_line, t_environment *s_env, t_line *s_line)
{
	char	**a_line_unset;
	int		i;
	int		x;

	a_line_unset = ft_split(a_line, ' ');
	if (!a_line_unset)
		ft_malloc_error(s_line, s_env, NULL);
	i = 1;
	if (!a_line_unset[1])
		return ;
	else
	{
		while (a_line_unset[i] != 0)
		{
			if (ft_strchr(a_line_unset[i], '=') != 0)
				return ;
			x = 0;
			ft_unset2(a_line_unset, s_env, i, x);
			i++;
		}
	}
	ft_free_env2(a_line_unset);
	s_line->exit_code = 0;
}
