/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:59:42 by julien            #+#    #+#             */
/*   Updated: 2022/07/02 01:57:10 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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

void	ft_memset(char *str)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
		str[i++] = 0;
}

void	ft_strcpy(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
}

int	end_line(char *residu)
{
	int	i;

	i = 0;
	while (residu[i])
	{
		if (residu[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, t_list *filed)
{
	char	*str;
	size_t	i[2];

	if (filed->save.is_finish[filed->save.index_currentfd])
	{
		if (s1[0] == 0)
		{
			free(s1);
			return (NULL);
		}
		free(s2);
		return (s1);
	}
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i[0] = -1;
	while (s1[++i[0]])
		str[i[0]] = s1[i[0]];
	i[1] = -1;
	while (s2[++i[1]])
		str[i[0]++] = s2[i[1]];
	str[i[0]] = 0;
	free(s1);
	free(s2);
	return (str);
}
