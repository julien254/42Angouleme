/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:56:10 by jdetre            #+#    #+#             */
/*   Updated: 2023/11/08 08:25:25 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
			count++;
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
	while (start <= end)
	{
		substr[i] = str[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_split(const char *s, char c)
{
	int		start;
	int		i;
	int		j;
	int		size;
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
			while (s[i] != c && s[i])
				i++;
			split[j++] = substr(s, start, i - 1);
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}

int	main(int argc, char *argv[])
{
	char	**split;
	int		i;

	i = 0;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[i])
		{
			printf("%s\n", split[i]);
			free(split[i++]);
		}
		free(split);
	}
	return (0);
}
