/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_protections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:09:01 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/18 14:39:58 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_pipe_error(t_line *s_line, t_environment *s_env,
	t_redirect *s_redirect)
{
	ft_malloc_error_s_line(s_line);
	ft_malloc_error_s_env(s_env);
	ft_malloc_error_s_redirect(s_redirect);
	write(2, "pipe error\n", 11);
	exit(1);
}

void	ft_dup2_error(t_line *s_line, t_environment *s_env,
	t_redirect *s_redirect)
{
	ft_malloc_error_s_line(s_line);
	ft_malloc_error_s_env(s_env);
	ft_malloc_error_s_redirect(s_redirect);
	write(2, "dup2 error\n", 11);
	exit(1);
}

void	ft_dup_error(t_line *s_line, t_environment *s_env,
	t_redirect *s_redirect)
{
	ft_malloc_error_s_line(s_line);
	ft_malloc_error_s_env(s_env);
	ft_malloc_error_s_redirect(s_redirect);
	write(2, "dup error\n", 10);
	exit(1);
}

void	ft_fork_error(t_line *s_line, t_environment *s_env,
	t_redirect *s_redirect)
{
	ft_malloc_error_s_line(s_line);
	ft_malloc_error_s_env(s_env);
	ft_malloc_error_s_redirect(s_redirect);
	write(2, "fork error\n", 11);
	exit(1);
}
