/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:29:23 by julien            #+#    #+#             */
/*   Updated: 2022/10/18 18:10:23 by julien           ###   ########.fr       */
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
	ft_verif_malloc(sub);
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
	ft_verif_malloc(split);
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
