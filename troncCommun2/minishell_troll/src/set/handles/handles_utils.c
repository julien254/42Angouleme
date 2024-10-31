/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:10:12 by gcannaud          #+#    #+#             */
/*   Updated: 2024/07/13 18:35:20 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_quote_skip(t_line *s_line, int i)
{
	char	c;
	int		s;

	s = i;
	c = s_line->a_line[i];
	i++;
	while (s_line->a_line[i] != 0 && s_line->a_line[i] != c)
		i++;
	if (s_line->a_line[i] == 'c')
		return (i);
	else if (s_line->a_line[i] == 0)
		return (s);
	i++;
	return (i);
}

int	ft_quote_skip_char(char *a_line, int i)
{
	char	c;
	int		s;

	s = i;
	c = a_line[i];
	i++;
	while (a_line[i] != 0 && a_line[i] != c)
		i++;
	if (a_line[i] == 0)
		return (s);
	return (i);
}

char	*ft_quote_skip_char_sup(char *a_line)
{
	char	c;
	int		i;

	i = 0;
	c = a_line[i];
	i++;
	if (a_line[i] == 0)
		return (a_line);
	while (a_line[i] != c)
		i++;
	a_line = ft_substr(a_line, 1, ft_strlen(a_line) - 2);
	return (a_line);
}

char	*ft_new_a_line(t_a_line_browse *browse, char *env, int size, int i)
{
	char	*pre_handle;
	char	*post_handle;
	char	*half;

	pre_handle = NULL;
	post_handle = NULL;
	pre_handle = ft_substr(browse->a_line, 0, i);
	post_handle = ft_substr(browse->a_line, (i + size),
			(ft_strlen(browse->a_line) - (i + size)));
	free (browse->a_line);
	half = (ft_strjoin(getenv(env), post_handle));
	browse->i--;
	browse->i += ((ft_strlen(getenv(env)) - ft_strlen(env)));
	browse->a_line = ft_strjoin(pre_handle, half);
	free (half);
	free(pre_handle);
	free(post_handle);
	return (browse->a_line);
}

//-------------------------------------------------------------------