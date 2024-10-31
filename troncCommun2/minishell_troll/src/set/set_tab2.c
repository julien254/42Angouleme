/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:00:20 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/13 17:42:39 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_sep_choice_and_set_tab_sep(t_line *s_line,
	t_set_tab_value *set_value, t_environment *s_env, t_a_line_browse browse)
{
	set_value->check = 0;
	ft_check_redirections(s_line, set_value, s_env, browse);
	if (s_line->a_line[set_value->i] == '|' && set_value->check == 0)
	{
		s_line->tab_a_line[set_value->k][0] = ft_strdup("|");
		if (!s_line->tab_a_line[set_value->k][0])
			ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	}
	else if (s_line->a_line[set_value->i] == '<' && set_value->check == 0)
	{
		s_line->tab_a_line[set_value->k][0] = ft_strdup("<");
		if (!s_line->tab_a_line[set_value->k][0])
			ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	}
	else if (s_line->a_line[set_value->i] == '>' && set_value->check == 0)
	{
		s_line->tab_a_line[set_value->k][0] = ft_strdup(">");
		if (!s_line->tab_a_line[set_value->k][0])
			ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	}
	s_line->tab_sep = ft_realloc_int_tab(s_line, s_env, browse);
	s_line->tab_sep[s_line->i] = set_value->k + 1;
	s_line->i++;
	s_line->tab_sep[s_line->i] = 0;
}

void	ft_set_sep2(t_line *s_line, t_set_tab_value *set_value,
	t_environment *s_env, t_a_line_browse browse)
{
	free (s_line->tab_a_line[set_value->k]);
	s_line->tab_a_line[set_value->k] = NULL;
	s_line->tab_a_line[set_value->k] = ft_calloc(2, sizeof(char **));
	if (!s_line->tab_a_line[set_value->k])
		ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	ft_sep_choice_and_set_tab_sep(s_line, set_value, s_env, browse);
	set_value->k++;
	set_value->i++;
	s_line->tab_a_line[set_value->k] = ft_calloc(1, sizeof(char **));
	if (!s_line->tab_a_line[set_value->k])
		ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	while (s_line->a_line[set_value->i] == ' ')
		set_value->i++;
}

void	ft_set_sep(t_line *s_line, t_set_tab_value *set_value,
	t_environment *s_env, t_a_line_browse browse)
{
	int	check;

	check = 0;
	while (s_line->a_line[set_value->i] == '|'
		|| s_line->a_line[set_value->i] == '<'
		|| s_line->a_line[set_value->i] == '>'
		|| (ft_isdigit(s_line->a_line[set_value->i]) == 0
			&& s_line->a_line[set_value->i + 1] == '>'))
	{
		if (check != 0)
			s_line->tab_a_line = ft_realloc_tab(s_line->tab_a_line,
					s_line, s_env, browse);
		ft_set_sep2(s_line, set_value, s_env, browse);
		check = 1;
	}
}
