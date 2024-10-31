/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:53:01 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/18 14:11:20 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_exit_value_pipe(char *a_line, t_line *s_line, t_environment *s_env,
	t_redirect *s_redirect)
{
	int		i;
	char	*s_exit_value;
	int		i_exit_value;
	int		j;
	int		k;

	i = 4;
	while (a_line[i] == ' ')
		i++;
	if (a_line[i] == '\0')
		return (ft_exit_no_params(s_line));
	j = i;
	while (ft_isdigit(a_line[i]) == 0)
		i++;
	s_exit_value = ft_calloc((i - j) + 1, sizeof(char));
	if (!s_exit_value)
		ft_malloc_error(s_line, s_env, s_redirect);
	k = 0;
	while (j != i)
		s_exit_value[k++] = a_line[j++];
	i_exit_value = ft_atoi(s_exit_value);
	free(s_exit_value);
	return (i_exit_value);
}

int	ft_exit_str_pipe(char *a_line, int i, int j)
{
	char	*error_line;

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
	return (2);
}

int	ft_exit_check_params_pipe(t_line *s_line, int i, t_environment *s_env,
	t_redirect *s_redirect)
{
	int		j;

	while (s_line->a_line2[i] == ' ')
		i++;
	j = i;
	while (ft_isdigit(s_line->a_line2[i]) == 0)
		i++;
	while (s_line->a_line2[i] == ' ')
		i++;
	if (s_line->a_line2[i] == '\0')
		return (0);
	else if (ft_isdigit(s_line->a_line2[i]) == 1)
	{
		if (ft_exit_str_pipe(s_line->a_line2, i, j) == 2)
			return (2);
		else
			ft_malloc_error(s_line, s_env, s_redirect);
	}
	return (1);
}

int	ft_exit_pipe(t_line *s_line, t_environment *s_env, t_redirect *s_redirect)
{
	int	i;
	int	checkparams;

	checkparams = 0;
	if (s_line->a_line2)
	{
		i = 4;
		while (s_line->a_line2[i] == ' ')
			i++;
	}
	checkparams = ft_exit_check_params_pipe(s_line, 4, s_env, s_redirect);
	if (checkparams == 1)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		return (1);
	}
	else if (checkparams == 2)
		return (2);
	return (ft_exit_value_pipe(s_line->a_line2, s_line, s_env, s_redirect));
}
