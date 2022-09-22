/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:29:23 by julien            #+#    #+#             */
/*   Updated: 2022/09/22 11:39:27 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *str, char c)
{
	int	lock;
	int	i;

	i = 0;
	lock = 0;
	while (*str)
	{
		if (*str != c && lock == 0)
		{
			lock = 1;
			i++;
		}
		else if (*str == c)
			lock = 0;
		str++;
	}
	return (i);
}

static char	*substr(const char *str, size_t start, size_t end)
{
	char	*sub;
	int		i;

	i = 0;
	sub = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		sub[i++] = str[start++];
	sub[i] = '\0';
	return (sub);
}

int	ft_control(char const *s, char **split)
{
	if (!s || !split)
		return (1);
	if (s[0] == 0)
	{
		free(split);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	index[2];
	int		i2;
	char	**split;

	split = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (ft_control(s, split))
		return (NULL);
	index[0] = 0;
	index[1] = 0;
	i2 = -1;
	while (index[0] <= ft_strlen(s))
	{
		if (s[index[0]] != c && i2 < 0)
			i2 = index[0];
		else if ((s[index[0]] == c || index[0] == ft_strlen(s)) && i2 >= 0)
		{
			split[index[1]++] = substr(s, i2, index[0]);
			i2 = -1;
		}
		index[0]++;
	}
	split[index[1]] = 0;
	return (split);
}
