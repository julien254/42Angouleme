/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_fork_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:28:33 by gcannaud          #+#    #+#             */
/*   Updated: 2024/08/14 12:28:34 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_fillsave(char *a_line, char *name)
{
	int	fd;

	fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0777);
	ft_putstr_fd(a_line, fd);
	close(fd);
}

char	*ft_returnsave(void)
{
	int		fd;
	char	*line;
	char	*a_line;

	fd = open(".line", O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = NULL;
	a_line = calloc(1, 1);
	line = get_next_line(fd);
	while (line)
	{
		a_line = ft_deljoin(a_line, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (unlink(".line") != 0)
		return (a_line);
	return (a_line);
}

void	ft_exit_hear(char *line, char *tmp, char *a_line)
{
	free(line);
	free(tmp);
	free(a_line);
}

int	check_stop_condition(char *tmp, char *stop, int here_on)
{
	if ((here_on == 0 && ft_str_c_number(tmp, stop) == 0)
		|| (tmp == NULL
			|| (here_on != 0
				&& ft_strncmp(tmp, stop, (ft_strlen(stop) + 1)) != 0)))
		return (0);
	return (1);
}
