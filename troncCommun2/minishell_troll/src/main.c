/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:15:35 by uguidoni          #+#    #+#             */
/*   Updated: 2024/08/21 10:53:55 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_check_exit(t_line *s_line)
{
	int	i;

	i = 4;
	if (ft_strncmp(s_line->a_line, "exit", 4) != 0)
		return (1);
	while (s_line->a_line[i] == ' ')
		i++;
	if (s_line->a_line[i] == '|')
		return (1);
	if (s_line->a_line[4] != ' ' && s_line->a_line[4] != '\0')
		return (1);
	return (0);
}

t_line	*ft_set_s_line(t_environment *s_env)
{
	t_line	*s_line;

	s_line = ft_calloc(1, sizeof(t_line));
	if (!s_line)
		ft_malloc_error(s_line, s_env, NULL);
	return (s_line);
}

t_environment	*ft_set_env(int ac, char **av, char **envp)
{
	t_environment	*s_env;

	(void)ac;
	(void)av;
	s_env = ft_calloc(1, sizeof(t_environment));
	if (!s_env)
		ft_malloc_error(NULL, s_env, NULL);
	s_env->env = ft_tabcpy(envp, 1);
	if (!s_env->env)
		ft_malloc_error(NULL, s_env, NULL);
	s_env->export = ft_tabcpy(envp, 1);
	if (!s_env->export)
		ft_malloc_error(NULL, s_env, NULL);
	return (s_env);
}

void	ft_apply(t_line *s_line, t_environment *s_env)
{
	int	i;

	i = 0;
	while (s_line->a_line[i] == ' ')
		i++;
	if (s_line->a_line[i] == '\0')
	{
		free(s_line->a_line);
		s_line->a_line = ft_strdup("");
	}
	if (s_line->a_line[0])
		add_history(s_line->a_line);
	s_line->a_line = ft_handles_quote(s_line, s_env);
	s_line->a_line = ft_heredoc(s_line->a_line, s_env);
	if (s_line->a_line[0] != '\0')
		ft_exec(s_line, s_env);
	ft_free_s_line(s_line, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_environment	*s_env;
	t_line			*s_line;

	if (!envp || !*envp)
	{
		ft_printf("Error: no environment\n");
		return (1);
	}
	s_env = ft_set_env(ac, av, envp);
	s_line = ft_set_s_line(s_env);
	while (1)
	{
		ft_sig();
		s_line->a_line = readline("minishell> ");
		if (g_global == 2)
		{
			s_line->exit_code = 130;
			g_global = 0;
		}
		if (!s_line->a_line || ft_check_exit(s_line) == 0)
			ft_exit(s_line, s_env);
		else
			ft_apply(s_line, s_env);
	}
}
