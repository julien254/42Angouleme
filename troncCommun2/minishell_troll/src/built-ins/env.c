/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:53:25 by uguidoni          #+#    #+#             */
/*   Updated: 2024/06/20 10:38:23 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_getenv(char *arg, char **env)
{
	int	size_arg;
	int	i;

	size_arg = ft_strlen(arg);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], arg, size_arg) == 0 && env[i][size_arg] == '=')
			return (env[i] + size_arg + 1);
		i++;
	}
	return (NULL);
}

void	ft_env(char **env, char *a_line, t_line *s_line)
{
	int	i;

	i = 3;
	while (a_line[i] == ' ')
		i++;
	if (a_line[i] == '\0')
	{
		i = 0;
		while (env[i] != 0)
		{
			ft_printf("%s\n", env[i]);
			i++;
		}
		s_line->exit_code = 0;
		return ;
	}
	write(2, "minishell: parse error\n", 23);
	s_line->exit_code = 1;
}
