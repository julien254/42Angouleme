/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_protection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:07:39 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/13 17:01:36 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_malloc_error_set_tab(t_line *s_line, t_environment *s_env,
	t_redirect *s_redirect, t_a_line_browse browse)
{
	free(browse.a_line);
	ft_malloc_error(s_line, s_env, s_redirect);
}

void	ft_malloc_error_s_redirect(t_redirect *s_redirect)
{
	if (s_redirect)
	{
		if (s_redirect->cmdpath)
			free(s_redirect->cmdpath);
		if (s_redirect->path)
			ft_free_env2(s_redirect->path);
		free(s_redirect);
	}
}

void	ft_malloc_error_s_env(t_environment *s_env)
{
	if (s_env)
	{
		if (s_env->env)
			ft_free_env2(s_env->env);
		if (s_env->export)
			ft_free_env2(s_env->export);
		free(s_env);
	}
}

void	ft_malloc_error_s_line(t_line *s_line)
{
	if (s_line)
	{
		if (s_line->a_line2)
			free(s_line->a_line2);
		if (s_line->a_line)
			free(s_line->a_line);
		if (s_line->tab_sep)
			free(s_line->tab_sep);
		if (s_line->tab_a_line)
			ft_free_tab_a_line(s_line->tab_a_line);
		free (s_line);
	}
}

void	ft_malloc_error(t_line *s_line, t_environment *s_env,
	t_redirect *s_redirect)
{
	ft_malloc_error_s_line(s_line);
	ft_malloc_error_s_env(s_env);
	ft_malloc_error_s_redirect(s_redirect);
	write(2, "malloc error\n", 13);
	exit(1);
}
