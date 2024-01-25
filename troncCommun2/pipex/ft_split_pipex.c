/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:56:10 by jdetre            #+#    #+#             */
/*   Updated: 2024/01/20 02:44:00 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	search_quote(int *i, char *str)
{
	*i = *i + 1;
	while (str[*i] != '\'' && str[*i] != '\"')
        *i = *i + 1;	
    *i = *i + 1;	
}
int	count_word(const char *str, char sep)
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
			if (str[i] == '\'' || str[i] == '\"')
			{	
				i++;
				while (str[i] != '\'' && str[i] != '\"')
					i++;

			}
			count++;
		}
		i++;
	}
	return (count);
}

char	*substr(const char *str, int start, int end)
{
	int		size;
	char	*substr;
	int		i;

	size = (end - start) + 1;
	substr = (char *)malloc((size + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	if (str[start] == '\'' || str[start] == '\"')
		start++;
	if (str[end] == '\'' || str[end] == '\"')
		end--;
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
			if (s[i] == '\'' || s[i] == '\"')
				search_quote(&i, (char *)s);
			else
			{
			while (s[i] != c && s[i])
				i++;
			}
			split[j++] = substr(s, start, i - 1);
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}
