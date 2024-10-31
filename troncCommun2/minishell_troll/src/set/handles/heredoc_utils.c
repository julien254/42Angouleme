/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:33:26 by gcannaud          #+#    #+#             */
/*   Updated: 2024/08/14 12:33:29 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_look_spac(char *str)
{
	int	c;

	c = 2;
	while (str[c])
	{
		while (str[c] && str[c] == ' ')
			c++;
		while (str[c] && str[c] != ' ')
			c++;
		if (str[c] && str[c] == ' ')
			return ((c - 3));
	}
	return (c);
}

int	ft_look_spac2(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		while (str[c] && str[c] == ' ')
			c++;
		while (str[c] && str[c] != ' ')
			c++;
		while (str[c] && str[c] == ' ')
			c++;
		return ((c) + 2);
	}
	return (c + 2);
}

char	*ft_clen_here(char *str)
{
	int	i;
	int	c;
	int	s;
	int	and;

	i = 0;
	c = 0;
	and = ft_strlen(str);
	while (i < and || str[i] != 0)
	{
		if (ft_strncmp(&str[i], "<<", 2) == 0)
		{
			s = i;
			c = (ft_look_spac2(&str[i + 2]));
			str = ft_strjoin(ft_substr(str, 0, s),
					ft_substr(str, (c + i), ft_strlen(str)));
			c = 0;
			i = -1;
		}
		i++;
	}
	return (str);
}

int	ft_index_here(t_sort *here)
{
	int		i;
	t_sort	*first;

	first = here;
	i = 1;
	while (here)
	{
		here->index = i;
		i++;
		here = here->next;
	}
	return (i);
}
