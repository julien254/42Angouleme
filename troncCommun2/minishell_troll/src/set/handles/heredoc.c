/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:55:46 by gcannaud          #+#    #+#             */
/*   Updated: 2024/07/16 17:12:24 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*exe_here(t_sort *here,
	char *a_line, t_environment *s_env)
{
	t_a_line_browse	browse;

	while (here && here->index < 17)
	{
		browse.a_line = ft_strdup(a_line);
		browse.i = 2 + ft_strlen(here->content);
		browse.a_line = ft_write_term_sav(browse.a_line, s_env,
				here->content, here->index);
		if (browse.a_line == NULL)
		{
			return (ft_strdup(""));
		}
		here = here->next;
	}
	a_line = ft_clen_here(a_line);
	return (a_line);
}

int	skip_space_here(char *a_line)
{
	int	i;

	i = 2;
	while (a_line[i] == ' ')
		i++;
	return (i);
}

char	*ft_heredoc(char *a_line, t_environment *s_env)
{
	t_sort			*here;
	int				i;

	i = 0;
	here = NULL;
	while (a_line[i])
	{
		if (ft_strncmp(&a_line[i], "<<", 2) == 0)
		{
			if (!here)
				here = ft_sortnew(ft_substr(&a_line[i],
							skip_space_here(&a_line[i]),
							ft_look_spac(&a_line[i])));
			else
				ft_sortadd_back(&here, ft_sortnew(ft_substr(&a_line[i],
							skip_space_here(&a_line[i]),
							ft_look_spac(&a_line[i]))));
			i = i + 2;
		}
		i++;
	}
	if (ft_index_here(here) >= 16)
		exit (2);
	a_line = exe_here(here, a_line, s_env);
	return (a_line);
}
