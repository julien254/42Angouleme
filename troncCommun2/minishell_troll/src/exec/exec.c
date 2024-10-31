/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:46:55 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/27 12:27:04 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"	

void	ft_reset_a_line(t_line *s_line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	free(s_line->a_line);
	s_line->a_line = ft_calloc(1, 1);
	while (s_line->tab_a_line[0][i] != 0)
	{
		tmp = ft_strjoin(s_line->a_line, s_line->tab_a_line[0][i]);
		free(s_line->a_line);
		s_line->a_line = ft_strdup(tmp);
		s_line->a_line = ft_strdeljoin(s_line->a_line, ft_strdup(" "));
		free(tmp);
		i++;
	}
}

int	ft_redirect(t_redirect *s_redirect, t_line *s_line,
	t_environment *s_env, int i)
{
	if (ft_strcmp(s_line->tab_a_line[i][0], "|") == 0)
	{
		ft_pipe(s_redirect, s_line, s_env);
		s_redirect->i = i + 1;
	}
	else
	{
		if (ft_strcmp(s_line->tab_a_line[i][0], ">") == 0 && (i == 0 ||
				(s_line->tab_sep[i - 2] != 0 &&
				(ft_strcmp(s_line->tab_a_line[i - 1][0], "|") == 0 ||
				ft_strcmp(s_line->tab_a_line[i - 1][0], ">") == 0 ||
				ft_strcmp(s_line->tab_a_line[i - 1][0], "<") == 0))))
			i = i + ft_redirection_weird(s_redirect, s_line, s_env, i);
		else if (ft_strcmp(s_line->tab_a_line[i][0], ">") == 0
				|| (ft_isdigit(s_line->tab_a_line[i][0][0] == 0)
				&& ft_strcmp(&s_line->tab_a_line[i][0][1], ">") == 0))
			i = i + ft_redirection(s_redirect, s_line, s_env, i);
		if (ft_strcmp(s_line->tab_a_line[i][0], "<") == 0)
			i = i + ft_redirection2(s_redirect, s_line, s_env, i);
	}
	return (i);
}

t_redirect	*ft_set_s_redirect(t_environment *s_env, t_line *s_line)
{
	t_redirect	*s_redirect;

	s_redirect = malloc(sizeof(t_redirect));
	s_redirect->path = ft_split(ft_path(s_line, s_env, NULL, 1), ':');
	s_redirect->save_stdin = dup(STDIN_FILENO);
	s_redirect->save_stdout = dup(STDOUT_FILENO);
	s_redirect->cmdpath = NULL;
	s_redirect->pipefd[0] = 0;
	s_redirect->pipefd[1] = 0;
	s_redirect->fd_in = STDIN_FILENO;
	s_redirect->fd_out = STDOUT_FILENO;
	s_redirect->fd_redirect = STDOUT_FILENO;
	s_redirect->fd_name = NULL;
	s_redirect->fd_here_on = 0;
	s_redirect->i = 0;
	return (s_redirect);
}

void	ft_is_redirect(t_line *s_line, t_environment *s_env)
{
	t_redirect	*s_redirect;
	int			i;
	int			j;

	i = 0;
	s_redirect = ft_set_s_redirect(s_env, s_line);
	while (s_line->tab_a_line[i][0] != 0)
	{
		if (ft_white_list(s_line, i) == 0)
		{
			j = 0;
			while (s_line->tab_sep[j] != 0)
			{
				if (s_line->tab_sep[j] - 1 == i)
					i = ft_redirect(s_redirect, s_line, s_env, i);
				j++;
			}
		}
		i++;
	}
	if (s_line->tab_a_line[i - 1][0] && s_line->tab_sep[j - 1] != i)
		ft_lastcmd(s_redirect, s_line, s_env);
	free(s_redirect);
}

void	ft_exec(t_line *s_line, t_environment *s_env)
{
	if (!s_line->tab_a_line)
		return ;
	if (ft_exec_error(s_line) == 1)
		return ;
	if (!s_line->tab_a_line[1][0])
	{
		ft_call_funcs(s_line, s_env);
		return ;
	}
	ft_is_redirect(s_line, s_env);
}
