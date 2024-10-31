/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:15:01 by gcannaud          #+#    #+#             */
/*   Updated: 2024/06/19 13:04:41 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	g_global = 0;

void	ft_sig_result(int sig)
{
	(void)sig;
	g_global = 2;
	if (wait(0) == -1)
	{
		ft_printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		ft_printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
	}
}

void	ft_catc(void)
{
	ft_printf("\n");
}

void	ft_sig(void)
{
	signal(SIGINT, ft_sig_result);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_exitsig(int sig)
{
	(void)sig;
	signal(SIGINT, SIG_IGN);
	g_global = 1;
	close(0);
}

void	ft_sig_handle(void)
{
	signal(SIGINT, ft_exitsig);
	signal(SIGQUIT, SIG_IGN);
}
