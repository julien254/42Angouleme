/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:30:52 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/16 16:02:28 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_s_line(t_line *s_line, int f)
{
	if (f != 2)
	{
		if (s_line->tab_a_line)
			ft_free_tab_a_line(s_line->tab_a_line);
		if (s_line->tab_sep)
			free(s_line->tab_sep);
		free(s_line->a_line);
		if (f == 1)
			free(s_line);
	}
	else
	{
		free(s_line->a_line);
		free(s_line);
	}
}

void	ft_free_tab_a_line(char ***tab_a_line)
{
	int	i;
	int	j;

	i = 0;
	while (tab_a_line[i][0] != 0)
	{
		j = 0;
		while (tab_a_line[i][j] != 0)
		{
			free (tab_a_line[i][j]);
			tab_a_line[i][j] = NULL;
			j++;
		}
		free (tab_a_line[i]);
		tab_a_line[i] = NULL;
		i++;
	}
	free(tab_a_line[i]);
	tab_a_line[i] = NULL;
	free (tab_a_line);
	tab_a_line = NULL;
}

void	ft_free_env3(char **env)
{
	int	i;

	i = 1;
	while (env[i] != 0)
	{
		free(env[i]);
		i++;
	}
	free(env);
}

void	ft_free_env2(char **env)
{
	int	i;

	i = 0;
	while (env[i] != 0)
	{
		free(env[i]);
		i++;
	}
	free(env);
}

void	ft_free_env(t_environment *s_env)
{
	int	i;

	i = 0;
	while (s_env->env[i] != 0)
	{
		free(s_env->env[i]);
		i++;
	}
	free(s_env->env);
	i = 0;
	while (s_env->export[i] != 0)
	{
		free(s_env->export[i]);
		i++;
	}
	free(s_env->export);
	free(s_env);
}
