/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:56:49 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/18 14:11:58 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_exit_no_params(t_line *s_line)
{
	if (s_line->exit_code == 127)
		return (127);
	return (0);
}

int	ft_exit_value(t_line *s_line, t_environment *s_env)
{
	int		i;
	char	*s_exit_value;
	int		i_exit_value;
	int		j;
	int		k;

	i = 4;
	while (s_line->a_line[i] == ' ')
		i++;
	if (s_line->a_line[i] == '\0')
		return (ft_exit_no_params(s_line));
	j = i;
	while (ft_isdigit(s_line->a_line[i]) == 0)
		i++;
	s_exit_value = ft_calloc((i - j) + 1, sizeof(char));
	if (!s_exit_value)
		ft_malloc_error(s_line, s_env, NULL);
	k = 0;
	while (j != i)
		s_exit_value[k++] = s_line->a_line[j++];
	i_exit_value = ft_atoi(s_exit_value);
	ft_free_s_line(s_line, 2);
	free(s_exit_value);
	return (i_exit_value);
}

int	ft_exit_str(char *a_line, int i, int j, t_environment *s_env)
{
	char	*error_line;

	ft_free_env(s_env);
	i = j;
	while (a_line[i] != '\0' && a_line[i] != ' ')
		i++;
	error_line = ft_calloc((i - j) + 2, sizeof(char));
	if (!error_line)
		return (1);
	i = 0;
	while (a_line[j] != '\0' && a_line[j] != ' ')
		error_line[i++] = a_line[j++];
	write(2, "minishell: exit: ", 17);
	ft_putstr_fd(error_line, 2);
	write(2, ": numeric argument required\n", 28);
	free(error_line);
	free(a_line);
	exit(2);
}

int	ft_exit_check_params(t_line *s_line, int i, t_environment *s_env)
{
	int		j;

	while (s_line->a_line[i] == ' ')
		i++;
	j = i;
	while (ft_isdigit(s_line->a_line[i]) == 0)
		i++;
	if (s_line->a_line[i] == ' ' || s_line->a_line[i] == '\0')
		i--;
	if (ft_isdigit(s_line->a_line[i]) == 1)
	{
		if (ft_exit_str(s_line->a_line, i, j, s_env) == 1)
			ft_malloc_error(s_line, s_env, NULL);
	}
	i++;
	while (s_line->a_line[i] == ' ')
		i++;
	if (s_line->a_line[i] == '\0')
		return (0);
	return (1);
}

void	ft_exit(t_line *s_line, t_environment *s_env)
{
	int	tmp;
	int	i;

	tmp = s_line->exit_code;
	write(2, "exit\n", 5);
	if (s_line->a_line)
	{
		i = 4;
		while (s_line->a_line[i] == ' ')
			i++;
	}
	if (!s_line->a_line || s_line->a_line[i] == '\0')
	{
		ft_free_env(s_env);
		ft_free_s_line(s_line, 2);
		exit(tmp);
	}
	if (ft_exit_check_params(s_line, 4, s_env) == 1)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		s_line->exit_code = 1;
		return ;
	}
	ft_free_env(s_env);
	exit(ft_exit_value(s_line, s_env));
}
