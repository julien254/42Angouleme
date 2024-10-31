/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:51:49 by gcannaud          #+#    #+#             */
/*   Updated: 2024/07/16 17:32:18 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_browse_for_char(t_a_line_browse *browse,
	t_environment *s_env, char *c)
{
	int	save;

	if (ft_strcmp(&browse->a_line[browse->i], c) == 0)
	{
		save = browse->i;
		browse->i++;
		while (ft_strcmp(&browse->a_line[browse->i], c) != 0)
		{
			if (browse->a_line[browse->i] == 0)
				browse->a_line = ft_write_term(browse->a_line, s_env, c, 0);
			if (browse->a_line == NULL)
				return ;
			if (browse->a_line[browse->i] == 0)
				break ;
			browse->i++;
		}
		if (ft_strcmp(&browse->a_line[browse->i], c) == 0)
		{
			browse->i++;
			if (ft_strcmp(c, "\'") != 0)
				browse->a_line = ft_handles_operator(browse, s_env->env,
						save, browse->i);
			browse->sucses++;
		}
	}
}

void	ft_browse(t_a_line_browse *browse, t_environment *s_env)
{
	int	save;

	save = 0;
	save = browse->i;
	while (browse->a_line[browse->i] != '"'
		&& browse->a_line[browse->i] != '\''
		&& browse->a_line[browse->i] != '\0')
		browse->i++;
	browse->a_line = ft_handles_operator(browse, s_env->env,
			save, browse->i);
	browse->sucses++;
}

char	*ft_handles_quote(t_line *s_line, t_environment *s_env)
{
	t_a_line_browse	browse;

	browse.a_line = ft_strdup(s_line->a_line);
	browse.exit_code = s_line->exit_code;
	browse.sucses = 0;
	browse.i = 0;
	while (browse.a_line[browse.i] != 0)
	{
		ft_browse(&browse, s_env);
		if (browse.a_line == NULL)
			return (ft_strdup(""));
		ft_browse_for_char(&browse, s_env, "\"");
		if (browse.a_line == NULL)
			return (ft_strdup(""));
		ft_browse_for_char(&browse, s_env, "'");
		if (browse.a_line == NULL)
			return (ft_strdup(""));
		if (browse.sucses == 0)
			browse.i++;
		browse.sucses = 0;
	}
	browse.a_line = ft_set_a_line_tab(s_line, browse, s_env);
	return (browse.a_line);
}
