/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:51:16 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/25 13:51:47 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_child(t_redirect *s_redirect, t_line *s_line,
	t_environment *s_env, int i)
{
	if (i == 1)
	{
		ft_free_s_line(s_line, 1);
		ft_free_env(s_env);
		close(s_redirect->save_stdin);
		close(s_redirect->save_stdout);
		free(s_redirect->cmdpath);
		ft_free_pipe(s_redirect);
		return ;
	}
	close(s_redirect->pipefd[0]);
	dup2(s_redirect->save_stdin, STDIN_FILENO);
	dup2(s_redirect->save_stdout, STDOUT_FILENO);
	close(s_redirect->save_stdin);
	close(s_redirect->save_stdout);
	ft_free_pipe(s_redirect);
}

void	ft_free_pipe(t_redirect *s_redirect)
{
	int	i;

	i = 0;
	if (s_redirect->path)
	{
		while (s_redirect->path[i] != 0)
		{
			free(s_redirect->path[i]);
			i++;
		}
		free(s_redirect->path);
	}
}
