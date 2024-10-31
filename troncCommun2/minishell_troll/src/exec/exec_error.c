/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:34:34 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/26 15:25:30 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_point_error(char *cmd, char *cmd_next)
{
	if (cmd[0] == '.')
	{
		if (cmd[1] == '\0' && cmd_next == 0)
		{
			write(2, "minishell: .: filename argument required\n", 42);
			write(2, ".: usage: . filename [arguments]\n", 34);
			return (1);
		}
		else if (cmd[1] == '.' && cmd[2] == '\0')
		{
			write(2, "..: command not found\n", 22);
			return (1);
		}
		if (cmd_next)
		{
			write(2, "minishell: parse error\n", 23);
			return (1);
		}
	}
	return (0);
}

int	ft_near_unexpected_token(t_line *s_line, int i, int j, int id)
{
	if (id == 1 && s_line->tab_sep[j] - 1 == i
		&& s_line->tab_sep[j + 1] - 1 == i + 1)
	{
		if (s_line->tab_sep[j + 2] - 1 == i + 2)
			write(2, "bash: syntax error near unexpected token `||'\n", 46);
		else
			write(2, "bash: syntax error near unexpected token `|'\n", 45);
		return (1);
	}
	if (id == 2 && (ft_strcmp(s_line->tab_a_line[0][0], "|") == 0
		&& s_line->tab_sep[0] == 1))
	{
		if (s_line->tab_a_line[1][0]
				&& ft_strcmp(s_line->tab_a_line[1][0], "|") == 0
				&& s_line->tab_sep[1] == 2)
			write(2, "bash: syntax error near unexpected token `||'\n", 46);
		else
			write(2, "bash: syntax error near unexpected token `|'\n", 45);
		return (1);
	}
	return (0);
}

int	ft_exec_error_while(t_line *s_line, int i, int j)
{
	while (s_line->tab_a_line[i][0] != 0)
	{
		if (ft_strcmp(s_line->tab_a_line[i][0], "|") == 0
		&& ft_strcmp(s_line->tab_a_line[i + 1][0], "|") == 0)
		{
			j = 0;
			while (s_line->tab_sep[j] != 0)
			{
				if (ft_near_unexpected_token(s_line, i, j, 1) == 1)
					return (1);
				j++;
			}
			i++;
		}
		i++;
	}
	return (0);
}

int	ft_exec_error(t_line *s_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s_line->tab_a_line[i][0] != 0)
		i++;
	while (s_line->tab_sep[j] != 0)
		j++;
	if (ft_strcmp(s_line->tab_a_line[i - 1][0], "|") == 0
			&& s_line->tab_sep[j - 1] == i)
	{
		write(2, "minishell: parse error\n", 23);
		return (1);
	}
	if (ft_near_unexpected_token(s_line, 0, 0, 2) == 1)
		return (1);
	if (ft_exec_error_while(s_line, 0, 0) == 1)
		return (1);
	return (0);
}
