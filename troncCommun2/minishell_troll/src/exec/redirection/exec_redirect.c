/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:40:49 by gcannaud          #+#    #+#             */
/*   Updated: 2024/07/27 12:11:18 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_redirection_weird(t_redirect *s_redirect, t_line *s_line,
	t_environment *s_env, int i)
{
	(void)s_redirect;
	(void)s_line;
	(void)s_env;
	(void)i;
	ft_printf("t'es chelou frerot\n");
	return (1);
}

int	ft_redirection(t_redirect *s_redirect, t_line *s_line,
	t_environment *s_env, int i)
{
	int	fd;

	(void)s_env;
	if ((s_line->tab_a_line[i][0][0] == '>'
		&& s_line->tab_a_line[i][0][1] == '>' )
		|| (s_line->tab_a_line[i][0][1] != 0
		&& s_line->tab_a_line[i][0][2] == '>' ))
		fd = open(s_line->tab_a_line[i + 1][0], O_CREAT | O_RDWR
				| O_APPEND, 0644);
	else
		fd = open(s_line->tab_a_line[i + 1][0], O_CREAT | O_RDWR
				| O_TRUNC, 0777);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(s_line->tab_a_line[i + 1][0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (0);
	}
	s_redirect->fd_out = fd;
	if (ft_isdigit(s_line->tab_a_line[i][0][0]) == 0)
		s_redirect->fd_redirect = (s_line->tab_a_line[i][0][0] - 48);
	return (1);
}

char	*ft_fd_load(void)
{
	int		i;
	int		fd;
	char	*tmp_name;

	i = 0;
	fd = -1;
	while (i < 16 && fd == -1)
	{
		tmp_name = ft_strjoin("test", ft_itoa(i));
		fd = open(tmp_name, O_RDONLY);
		if (fd != -1)
			close(fd);
		free(tmp_name);
		i++;
	}
	if (fd != -1)
		return (ft_strjoin("test", ft_itoa(i - 1)));
	return (NULL);
}

int	ft_redirection2(t_redirect *s_redirect, t_line *s_line,
	t_environment *s_env, int i)
{
	int		fd;
	char	*fd_name;

	(void)s_env;
	if (s_line->tab_a_line[i][0][1] == '<')
	{
		fd_name = ft_fd_load();
		fd = open(fd_name, O_RDONLY);
		s_redirect->fd_here_on = 1;
		s_redirect->fd_name = ft_strdup(fd_name);
	}
	else
		fd = open(s_line->tab_a_line[i + 1][0], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(s_line->tab_a_line[i + 1][0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (0);
	}
	s_redirect->fd_in = fd;
	return (1);
}
