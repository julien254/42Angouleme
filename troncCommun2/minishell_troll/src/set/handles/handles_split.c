/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:38:08 by gcannaud          #+#    #+#             */
/*   Updated: 2024/08/14 12:38:09 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*handle_quote_aply_str(char *str, int *i, int *j)
{
	char	*tmp;

	tmp = ft_substr(str, 0, *i);
	*j = *i;
	*i = ft_quote_skip_char(str, *i);
	if (*i != *j)
	{
		str = ft_set_tmp(tmp, str, *i, *j);
		(*i)--;
	}
	else
	{
		free(tmp);
		*i = *j;
	}
	return (str);
}

char	*ft_skip_quot_in_str(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			str = handle_quote_aply_str(str, &i, &j);
		else
			i++;
	}
	return (str);
}

size_t	handle_quotes(char **s, size_t i)
{
	size_t	tmp;
	size_t	k;

	tmp = i;
	k = 0;
	while ((*s)[i] == '"' || (*s)[i] == '\'')
	{
		i = ft_quote_skip_char(*s, i) + 1;
		k += 2;
	}
	i -= k;
	*s = ft_skip_quot_in_str(*s, (*s)[tmp]);
	return (i);
}

size_t	split_word(char **s, char c, char **tab, size_t j)
{
	size_t	i;

	i = 0;
	while ((*s)[i] != c && (*s)[i] != '\0')
	{
		if (((*s)[i] == '"' || (*s)[i] == '\'') && (*s)[i + 1] != 0)
			i = handle_quotes(s, i);
		else
			i++;
	}
	tab[j] = ft_substr_split(*s, 0, i, tab);
	return (i);
}

char	**ft_handles_split(char *s, char c)
{
	char	**tab;
	size_t	j;

	if (s == NULL)
		return (NULL);
	tab = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	j = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
			s += split_word(&s, c, tab, j++);
	}
	tab[j] = 0;
	return (tab);
}
