/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:36:50 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/27 11:36:05 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_export_pipe(char *a_line, t_environment *s_env, t_line *s_line,
	t_redirect *s_redirect)
{
	char	**a_line_export;
	int		i;

	a_line_export = ft_split(a_line, ' ');
	if (!a_line_export)
		ft_malloc_error(s_line, s_env, s_redirect);
	i = 1;
	s_line->exit_code = 0;
	if (!a_line_export[1])
	{
		s_env->export = ft_sort_export(s_env->export);
		ft_print_export(s_env, 0);
		ft_free_env2(a_line_export);
		return ;
	}
	while (a_line_export[i] != 0)
	{
		if (ft_putexport_prev(a_line_export[i], s_env, s_line) == 1)
		{
			ft_free_env2(a_line_export);
			ft_malloc_error(s_line, s_env, s_redirect);
		}
		i++;
	}
	ft_free_env2(a_line_export);
}

void	ft_print_export(t_environment *s_env, int i)
{
	int	j;
	int	check;

	if (!s_env || !s_env->export)
		return ;
	while (s_env->export[i] != 0)
	{
		ft_printf("declare -x ");
		j = 0;
		check = 0;
		while (s_env->export[i][j])
		{
			ft_printf("%c", s_env->export[i][j]);
			if (s_env->export[i][j] == '=' && check == 0)
			{
				check = 1;
				ft_printf("\"");
			}
			j++;
		}
		if (check == 1)
			ft_printf("\"");
		ft_printf("\n");
		i++;
	}
}

void	ft_export(char *a_line, t_environment *s_env, t_line *s_line, int i)
{
	char	**a_line_export;

	a_line_export = ft_split(a_line, ' ');
	if (!a_line_export)
		ft_malloc_error(s_line, s_env, NULL);
	s_line->exit_code = 0;
	if (!a_line_export[1])
	{
		if (!s_env)
			return ;
		s_env->export = ft_sort_export(s_env->export);
		ft_print_export(s_env, 0);
		ft_free_env2(a_line_export);
		return ;
	}
	while (a_line_export[i] != 0)
	{
		if (ft_putexport(a_line_export[i], s_env, s_line) == 1)
		{
			ft_free_env2(a_line_export);
			ft_malloc_error(s_line, s_env, NULL);
		}
		i++;
	}
	ft_free_env2(a_line_export);
}
