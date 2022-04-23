/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:59:42 by julien            #+#    #+#             */
/*   Updated: 2022/04/22 17:21:49 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strdup(char *src, char end)
{
	int		i;
	char	*str;

	str = (char *)malloc(ft_strlen(src) + 1);
	i = 0;
	while (src[i] != end)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_strchr(char *s, t_list *filed)
{
	size_t	i;
	size_t	j;
	size_t	index_end_s;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			index_end_s = ++i;
			j = 0;
			while (s[i])
				filed->residu[j++] = s[i++];
			filed->residu[j] = 0;
			s[index_end_s] = '\0';
			break ;
		}
		i++;
	}
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = dstlen;
	if (dstlen < size - 1 && size > 0)
	{
		j = 0;
		while (i < size - 1 && src[j])
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	if (dstlen > size)
		dstlen = size;
	return (srclen + dstlen);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	size = ft_strlen(s1) + 1;
	if (size > 0)
	{
		while (i < size - 1 && s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
	}
	ft_strlcat(str, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s1[0] != 0)
		free(s1);
	free(s2);
	return (str);
}
