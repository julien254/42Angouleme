/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:39:41 by uguidoni          #+#    #+#             */
/*   Updated: 2024/06/20 12:51:05 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_putexport_no_equal(char *str, t_environment *s_env)
{
	int		i;

	i = 0;
	while (s_env->export[i] != 0)
	{
		if (ft_strchr(s_env->export[i], '=') == 0)
		{
			if (ft_strcmp(s_env->export[i], str) == 0)
				return (0);
		}
		if (ft_strncmp(s_env->export[i], str,
				ft_lequal2(s_env->export[i])) == 0)
		{
			if (ft_strlen(str) == (size_t)ft_lequal2(s_env->export[i]))
				return (0);
			if (ft_strncmp(s_env->export[i], str,
					ft_lequal2(s_env->export[i])) != 0)
				break ;
		}
		i++;
	}
	if (ft_add_envvar_export(str, s_env, i, 0) == 1)
		return (1);
	return (0);
}

int	ft_export_error(char *str)
{
	int	i;
	int	count;
	int	equal;

	i = 1;
	count = 0;
	equal = 0;
	if (ft_isalpha(str[0]) == 0 && str[0] != '_')
		return (1);
	while (str[i] != 0)
	{
		if (str[i] == '=')
			equal = 1;
		if (str[i] == '+' && equal == 0)
			count++;
		if ((ft_isalnum(str[i]) == 0 && str[i] != '_' && str[i] != '='
				&& str[i] != '+') || count > 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_putexport_prev(char *str, t_environment *s_env, t_line *s_line)
{
	if (ft_export_error(str) == 1)
	{
		write(2, "bash: export: `", 15);
		ft_putstr_fd(str, 2);
		write(2, "': not a valid identifier\n", 26);
		s_line->exit_code = 1;
		return (1);
	}
	if (ft_strchr(str, '=') == 0)
	{
		if (ft_putexport_no_equal(str, s_env) == 1)
			return (2);
		s_line->exit_code = 1;
		return (1);
	}
	if (str[ft_lequal2(str)] == '+')
	{
		if (ft_join_export(str, s_env, 0) == 1)
			return (2);
		if (ft_putenv(str, s_env) == 1)
			return (1);
		s_line->exit_code = 1;
		return (1);
	}
	return (0);
}

int	ft_putexport2(char *str, t_environment *s_env, int i)
{
	while (s_env->export[i] != 0)
	{
		if (ft_strncmp(s_env->export[i], str,
				ft_lequal2(s_env->export[i])) == 0)
		{
			if (ft_strncmp(s_env->export[i], str, ft_lequal2(str)) == 0)
			{
				free(s_env->export[i]);
				s_env->export[i] = ft_strdup(str);
				if (!s_env->export[i])
					return (1);
				if (ft_putenv(str, s_env) == 1)
					return (1);
				return (0);
			}
		}
		i++;
	}
	if (ft_add_envvar_export(str, s_env, i, 0) == 1)
		return (1);
	return (0);
}

int	ft_putexport(char *str, t_environment *s_env, t_line *s_line)
{
	int		i;

	i = ft_putexport_prev(str, s_env, s_line);
	if (i == 1)
		return (0);
	else if (i == 2)
		return (1);
	i = 0;
	if (ft_putexport2(str, s_env, i) == 1)
		return (1);
	if (ft_putenv(str, s_env) == 1)
		return (1);
	return (0);
}
