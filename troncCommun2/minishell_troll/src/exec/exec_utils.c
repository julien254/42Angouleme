/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:01:09 by gcannaud          #+#    #+#             */
/*   Updated: 2024/08/14 13:01:10 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"	

int	is_builtin_command(char *cmd, const char *builtin)
{
	int	result;

	result = (ft_strncmp(cmd, builtin, strlen(builtin) + 1) == 0);
	if (!result)
		result = (ft_strncmp(cmd, builtin, strlen(builtin)) == 0);
	return (result);
}

void	ft_call_funcs_pipe(t_redirect *s_redirect, t_line *s_line,
		t_environment *s_env)
{
	ft_set_a_line2(s_line, s_redirect);
	handle_builtin_commands(s_redirect, s_line, s_env);
	if (!is_builtin_command(s_line->tab_a_line[s_redirect->i][0], "unset"))
		execve(s_redirect->cmdpath, s_line->tab_a_line[s_redirect->i],
			s_env->env);
	free(s_line->a_line2);
}

void	ft_set_a_line2(t_line *s_line, t_redirect *s_redirect)
{
	int	count;
	int	j;

	count = 0;
	while (s_line->tab_a_line[s_redirect->i][count])
		count++;
	s_line->a_line2 = ft_calloc(count + 1, sizeof(char));
	j = 0;
	while (s_line->tab_a_line[s_redirect->i][j])
	{
		s_line->a_line2 = ft_strdeljoin(s_line->a_line2,
				ft_strdup(s_line->tab_a_line[s_redirect->i][j]));
		s_line->a_line2 = ft_strdeljoin(s_line->a_line2, ft_strdup(" "));
		j++;
	}
}

int	ft_white_list(t_line *s_line, int i)
{
	if (ft_strcmp(s_line->tab_a_line[i][0], "|") == 0
		|| ft_strcmp(s_line->tab_a_line[i][0], ">") == 0
		|| ft_strcmp(s_line->tab_a_line[i][0], "<") == 0
		|| (ft_isdigit(s_line->tab_a_line[i][0][0] == 0)
		&& ft_strcmp(&s_line->tab_a_line[i][0][1], ">") == 0))
		return (0);
	return (1);
}

void	ft_call_funcs(t_line *s_line, t_environment *s_env)
{
	ft_reset_a_line(s_line);
	if (ft_strncmp(s_line->tab_a_line[0][0], "echo", 5) == 0
		|| ft_strncmp(s_line->tab_a_line[0][0], "echo ", 5) == 0)
		ft_echo(s_line->a_line, s_line);
	else if (ft_strncmp(s_line->tab_a_line[0][0], "env", 4) == 0
		|| ft_strncmp(s_line->tab_a_line[0][0], "env ", 4) == 0)
		ft_env(s_env->env, s_line->a_line, s_line);
	else if (ft_strncmp(s_line->tab_a_line[0][0], "pwd", 4) == 0
		|| ft_strncmp(s_line->tab_a_line[0][0], "pwd ", 4) == 0)
	{
		ft_printf("%s\n", ft_getenv("PWD", s_env->env));
		s_line->exit_code = 0;
	}
	else if (ft_strncmp(s_line->tab_a_line[0][0], "export", 7) == 0
		|| ft_strncmp(s_line->tab_a_line[0][0], "export ", 7) == 0)
		ft_export(s_line->a_line, s_env, s_line, 1);
	else if (ft_strncmp(s_line->tab_a_line[0][0], "unset", 6) == 0
		|| ft_strncmp(s_line->tab_a_line[0][0], "unset ", 6) == 0)
		ft_unset(s_line->a_line, s_env, s_line);
	else if (ft_strncmp(s_line->tab_a_line[0][0], "cd", 3) == 0
		|| ft_strncmp(s_line->tab_a_line[0][0], "cd ", 3) == 0)
		ft_cd(s_line, s_env);
	else
		ft_execve(s_line, s_env);
}
