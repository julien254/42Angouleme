/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:42:24 by uguidoni          #+#    #+#             */
/*   Updated: 2024/05/02 13:50:33 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_substr_split(char const *s, unsigned int st, size_t l, char **t)
{
	size_t			i;
	size_t			len_m;
	char			*str;

	if (!s)
		return (NULL);
	len_m = ft_strlen(s) - st;
	if (len_m >= l)
		len_m = l;
	if (st > ft_strlen(s))
		len_m = 0;
	str = ft_calloc(len_m + 1, sizeof(char));
	if (str == NULL)
	{
		ft_free(t);
		return (NULL);
	}
	i = 0;
	while (i < len_m)
		str[i++] = s[st++];
	str[i] = '\0';
	return (str);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	tab = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	j = 0;
	while (*s != '\0')
	{
		if (s[0] == c)
			s++;
		else
		{
			i = 0;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[j++] = ft_substr_split(s, 0, i, tab);
			s += i;
		}
	}
	tab[j] = 0;
	return (tab);
}
