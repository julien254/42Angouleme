/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:19:14 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/17 16:32:56 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_set_a_line_tab3(t_line *s_line, t_set_tab_value *set_value,
	t_environment *s_env, t_a_line_browse browse)
{
	char	*tmp;

	tmp = ft_substr(browse.a_line, set_value->j, set_value->i - set_value->j);
	if (!tmp)
		ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	if (set_value->k != 0)
	{
		free (s_line->tab_a_line[set_value->k]);
		s_line->tab_a_line[set_value->k] = NULL;
	}
	s_line->tab_a_line[set_value->k] = ft_handles_split(tmp, ' ');
	if (!s_line->tab_a_line[set_value->k])
	{
		free(tmp);
		tmp = NULL;
		ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	}
	free (tmp);
	tmp = NULL;
	s_line->tab_a_line[set_value->k + 1] = ft_calloc(1, sizeof(char **));
	if (!s_line->tab_a_line[set_value->k + 1])
		ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
}

void	ft_set_a_line_tab2(t_line *s_line, t_set_tab_value *set_value,
	t_environment *s_env, t_a_line_browse browse)
{
	set_value->j = set_value->i;
	if (!s_line->tab_a_line)
	{
		s_line->tab_a_line = ft_calloc(4, sizeof(char ***));
		if (!s_line->tab_a_line)
			ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	}
	else
		s_line->tab_a_line = ft_realloc_tab(s_line->tab_a_line,
				s_line, s_env, browse);
	while (s_line->a_line[set_value->i] != '\0'
		&& s_line->a_line[set_value->i] != '|'
		&& s_line->a_line[set_value->i] != '<'
		&& s_line->a_line[set_value->i] != '>'
		&& (s_line->a_line[set_value->i + 1] != '>'
			|| ft_isdigit(s_line->a_line[set_value->i]) != 0))
	{
		if ((s_line->a_line[set_value->i] == '"'
				|| s_line->a_line[set_value->i] == '\'')
			&& s_line->a_line[set_value->i] != 0)
			set_value->i = ft_quote_skip(s_line, set_value->i);
		else
			set_value->i++;
	}
	ft_set_a_line_tab3(s_line, set_value, s_env, browse);
}

char	*ft_set_a_line_tab_while(t_line *s_line, t_set_tab_value *set_value,
	t_environment *s_env, t_a_line_browse browse)
{
	while ((size_t)set_value->i < ft_strlen(s_line->a_line))
	{
		ft_set_a_line_tab2(s_line, set_value, s_env, browse);
		set_value->k++;
		ft_set_sep(s_line, set_value, s_env, browse);
	}
	free(s_line->a_line);
	return (browse.a_line);
}

char	*ft_set_a_line_tab(t_line *s_line, t_a_line_browse browse,
	t_environment *s_env)
{
	t_set_tab_value	set_value;

	set_value.i = 0;
	set_value.k = 0;
	s_line->tab_a_line = NULL;
	s_line->i = 0;
	free(s_line->a_line);
	s_line->tab_sep = ft_calloc(1, sizeof(int));
	if (!s_line->tab_sep)
		ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	s_line->a_line = ft_strdup(browse.a_line);
	if (!s_line->a_line)
		ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	if (s_line->a_line[set_value.i] == '|' || s_line->a_line[set_value.i] == '<'
		|| s_line->a_line[set_value.i] == '>'
		|| (ft_isdigit(s_line->a_line[set_value.i]) == 0
			&& s_line->a_line[set_value.i + 1] == '>'))
	{
		s_line->tab_a_line = ft_calloc(4, sizeof(char ***));
		if (!s_line->tab_a_line)
			ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
		ft_set_sep(s_line, &set_value, s_env, browse);
	}
	browse.a_line = ft_set_a_line_tab_while(s_line, &set_value, s_env, browse);
	return (browse.a_line);
}
