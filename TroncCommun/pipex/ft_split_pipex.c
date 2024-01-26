/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:09:54 by judetre           #+#    #+#             */
/*   Updated: 2024/01/25 12:42:38 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void	search_quote(int *i, char *str, char c)
{
	if (str[*i] == '\'')
	{
		*i = *i + 1;
		while (str[*i] != '\'')
			*i = *i + 1;
		*i = *i + 1;
	}
	else
	{
		while (str[*i] != c && str[*i])
			*i = *i + 1;
	}
}

static int	count_word(const char *str, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (str[i++] != sep)
		count++;
	while (str[i])
	{
		if (str[i] != sep && str[i - 1] == sep)
		{
			if (str[i] == '\'')
			{
				i++;
				while (str[i] != '\'')
					i++;
			}
			count++;
		}
		i++;
	}
	return (count);
}

static char	*substr(const char *str, int start, int end)
{
	int		size;
	char	*substr;
	int		i;

	size = (end - start) + 1;
	substr = (char *)malloc((size + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	if (str[start] == '\'' && str[end] == '\'')
	{
		start++;
		end--;
	}
	while (start <= end)
	{
		substr[i] = str[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_split_pipex(const char *s, char c)
{
	int		start;
	int		i;
	int		j;
	char	**split;

	split = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			search_quote(&i, (char *)s, c);
			split[j++] = substr(s, start, i - 1);
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}
