/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:00:22 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/17 16:33:12 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_check_redirections3(t_line *s_line,
	t_set_tab_value *set_value, t_environment *s_env, t_a_line_browse browse)
{
	char	*tmp;

	tmp = NULL;
	if (set_value->check == 1)
		return ;
	if (ft_isdigit(s_line->a_line[set_value->i]) == 0
		&& s_line->a_line[set_value->i + 1] == '>')
	{
		tmp = ft_substr(s_line->a_line, set_value->i, 2);
		if (!tmp)
			ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
		s_line->tab_a_line[set_value->k][0] = ft_strdup(tmp);
		if (!s_line->tab_a_line[set_value->k][0])
		{
			free(tmp);
			ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
		}
		free(tmp);
		set_value->i++;
		set_value->check = 1;
	}
}

void	ft_check_redirections2(t_line *s_line,
	t_set_tab_value *set_value, t_environment *s_env, t_a_line_browse browse)
{
	char	*tmp;

	tmp = NULL;
	if (set_value->check == 1)
		return ;
	if (ft_isdigit(s_line->a_line[set_value->i]) == 0
		&& s_line->a_line[set_value->i + 1] == '>'
		&& s_line->a_line[set_value->i + 2] == '>')
	{
		tmp = ft_substr(s_line->a_line, set_value->i, 3);
		if (!tmp)
			ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
		s_line->tab_a_line[set_value->k][0] = ft_strdup(tmp);
		if (!s_line->tab_a_line[set_value->k][0])
		{
			free(tmp);
			ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
		}
		free(tmp);
		set_value->i += 2;
		set_value->check = 1;
	}
	else
		ft_check_redirections3(s_line, set_value, s_env, browse);
}

void	ft_check_redirections(t_line *s_line,
	t_set_tab_value *set_value, t_environment *s_env, t_a_line_browse browse)
{
	if (s_line->a_line[set_value->i] == '<'
		&& s_line->a_line[set_value->i + 1] == '<')
	{
		s_line->tab_a_line[set_value->k][0] = ft_strdup("<<");
		if (!s_line->tab_a_line[set_value->k][0])
			ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
		set_value->i++;
		set_value->check = 1;
	}
	else if (s_line->a_line[set_value->i] == '>'
		&& s_line->a_line[set_value->i + 1] == '>')
	{
		s_line->tab_a_line[set_value->k][0] = ft_strdup(">>");
		if (!s_line->tab_a_line[set_value->k][0])
			ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
		set_value->i++;
		set_value->check = 1;
	}
	ft_check_redirections2(s_line, set_value, s_env, browse);
}
