/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:49:07 by uguidoni          #+#    #+#             */
/*   Updated: 2023/12/22 13:29:18 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	gnl_ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (nmemb <= 0 || size <= 0)
		return (malloc(1));
	if (((nmemb * size) / nmemb) != size)
		return (NULL);
	if ((long)nmemb < 0 || (long)size < 0)
		return (NULL);
	str = malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*gnl_ft_strdup(char *s)
{
	char	*s2;
	int		i;

	s2 = gnl_ft_calloc(1, gnl_ft_strlen(s) + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = gnl_ft_calloc(gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1, 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	free(s1);
	return (str);
}

char	*gnl_ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	y;

	i = 0;
	y = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == y)
			return ((char *)&s[i]);
		i++;
	}
	if (y == 0)
		return ((char *)&s[i]);
	return (NULL);
}
