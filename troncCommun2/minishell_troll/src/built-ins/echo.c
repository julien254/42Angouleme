/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:12:10 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/25 14:55:08 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_print(char *a_line, int i)
{
	while (a_line[i] != '\0')
	{
		ft_printf("%c", a_line[i]);
		i++;
	}
}

int	ft_check_param(char *a_line, int i)
{
	if (a_line[i + 1] == '\0' || a_line[i + 1] != 'n')
		return (1);
	i++;
	while (a_line[i] == 'n')
		i++;
	if (a_line[i] == '\0' || a_line[i] == ' ')
		return (0);
	return (1);
}

void	ft_echo(char *a_line, t_line *s_line)
{
	int	i;
	int	check;

	i = 4;
	check = 0;
	while (a_line[i] == ' ')
		i++;
	if (a_line[i] == '-' && ft_check_param(a_line, i) == 0)
	{
		check = 1;
		i++;
		while (a_line[i] == ' ' || a_line[i] == 'n')
			i++;
	}
	ft_print(a_line, i);
	if (check == 0)
		ft_printf("\n");
	s_line->exit_code = 0;
}
