/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:27:07 by judetre           #+#    #+#             */
/*   Updated: 2024/02/19 18:37:33 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *str, char c)
{
	int	lock;
	int	i;

	i = 0;
	lock = 0;
	if (!str)
		return (0);
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
	int		start;
	size_t	j;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[j++] = substr(s, start, i);
			start = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
