/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:13:11 by gcannaud          #+#    #+#             */
/*   Updated: 2024/07/16 17:13:19 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*process_line(char *a_line, char *line, char *stop, int here_on)
{
	if (a_line)
		a_line = ft_str_add_char(a_line, "\n");
	else
		a_line = ft_calloc(1, 1);
	if (here_on == 0 || ft_strncmp(line, stop, (ft_strlen(stop) + 1)) != 0)
		a_line = ft_deljoin(a_line, line);
	return (a_line);
}

char	*ft_heer_read(char *a_line, char *stop, int here_on)
{
	char	*tmp;
	char	*line;

	tmp = NULL;
	line = NULL;
	while (!check_stop_condition(tmp, stop, here_on))
	{
		line = readline("> ");
		if ((!line && g_global == 0) || g_global == 1)
		{
			ft_exit_hear(line, tmp, a_line);
			return (NULL);
		}
		if (line != tmp)
		{
			a_line = process_line(a_line, line, stop, here_on);
			free(tmp);
			tmp = ft_strdup(line);
		}
		free(line);
	}
	free (tmp);
	return (a_line);
}

char	*ft_write_term(char *a_line,
	t_environment *s_env, char *c, int here_on)
{
	pid_t	pid;

	pid = 0;
	pid = fork();
	if (pid == -1)
		return (a_line);
	if (pid == 0)
	{
		ft_free_env(s_env);
		ft_sig_handle();
		a_line = ft_heer_read(a_line, c, here_on);
		if (a_line == NULL)
		{
			exit(130);
		}
		ft_fillsave(a_line, ".line");
		free(a_line);
		exit(0);
	}
	waitpid(pid, 0, 0);
	free(a_line);
	a_line = ft_returnsave();
	return (a_line);
}

void	ft_fork_in_term_sav(char *a_line, t_environment *s_env,
		char *c, int here_on)
{
	char	*tmp_name;

	ft_free_env(s_env);
	ft_sig_handle();
	free(a_line);
	a_line = NULL;
	a_line = ft_heer_read(a_line, c, here_on);
	if (a_line == NULL)
	{
		free(a_line);
		exit(0);
	}
	tmp_name = ft_strjoin("test", ft_itoa(here_on));
	ft_fillsave(a_line, tmp_name);
	free(tmp_name);
	free(a_line);
	exit(130);
}

char	*ft_write_term_sav(char *a_line, t_environment *s_env, char *c,
	int here_on)
{
	pid_t	pid;
	int		status;
	int		exit_code;

	exit_code = 0;
	pid = 0;
	if (c[0] == 0 || c[0] == '|' || c[0] == '<' || c[0] == '>')
	{
		printf("minishell: syntax error near unexpected token `%s'\n", c);
		return (NULL);
	}
	pid = fork();
	if (pid == -1)
		return (a_line);
	if (pid == 0)
		ft_fork_in_term_sav(a_line, s_env, c, here_on);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	if (exit_code == 0)
		return (NULL);
	return (a_line);
}
