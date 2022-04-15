/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:29:23 by julien            #+#    #+#             */
/*   Updated: 2022/04/11 18:47:23 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**calloc_split(char const *s, char c)
{
	size_t	i;
	char	**split;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	split = (char **)ft_calloc(sizeof(s) * (count + 2), 1);
	if (!split)
		return (NULL);
	return (split);
}

static void	*freeall(char **split, size_t t)
{
	size_t	i;

	i = 0;
	while (i < t)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static void	*apply_split(char **split, char const *s, \
		t_index *last, t_index *current)
{
	split[current->len] = ft_substr(s, last->i, last->len);
	if (!split[current->len])
		return (freeall(split, current->len));
	current->len++;
	return (split);
}

static void	*make_split(char **split, char const *s, char c)
{
	t_index	current;
	t_index	last;
	size_t	i;

	i = 0;
	current.i = 0;
	current.len = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			last.i = current.i;
			last.len = i - current.i;
			if (i > current.i && !apply_split(split, s, &last, &current))
				return (NULL);
			current.i = i + 1;
		}
		i++;
	}
	last.i = current.i;
	last.len = i - current.i;
	if (i > current.i && !apply_split(split, s, &last, &current))
		return (NULL);
	split[current.len] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = calloc_split(s, c);
	if (!split)
		return (NULL);
	if (!make_split(split, s, c))
		return (NULL);
	return (split);
}
