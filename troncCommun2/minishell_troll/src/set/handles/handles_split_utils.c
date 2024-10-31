/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_split_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:40:23 by gcannaud          #+#    #+#             */
/*   Updated: 2024/08/14 12:40:24 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_free(char **tab)
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

char	*ft_substr_split(char *s, unsigned int st, size_t l, char **t)
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

size_t	ft_count_words(char *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"'
			|| s[i] == '\'')
			i = ft_quote_skip_char(s, i);
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

char	*ft_set_tmp(char *tmp, char *str, int i, int j)
{
	char	*tmp2;
	char	*tmp3;

	tmp2 = NULL;
	tmp3 = NULL;
	tmp2 = ft_substr(str, j + 1, (i - 1) - j);
	tmp3 = ft_substr(str, i + 1, (ft_strlen(str) - i));
	i--;
	str = ft_strjoin(ft_strjoin(tmp, tmp2), tmp3);
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (str);
}
