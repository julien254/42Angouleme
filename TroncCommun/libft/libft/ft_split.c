/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:27:07 by judetre           #+#    #+#             */
/*   Updated: 2023/11/03 15:29:29 by judetre          ###   ########.fr       */
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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		i2;
	size_t	j;
	char	**split;

	split = malloc((count(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	i2 = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && i2 < 0)
			i2 = i;
		else if ((s[i] == c || i == ft_strlen(s)) && i2 >= 0)
		{
			split[j++] = substr(s, i2, i);
			i2 = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
