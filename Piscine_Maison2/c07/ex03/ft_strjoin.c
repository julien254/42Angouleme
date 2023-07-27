/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:29:39 by judetre            #+#    #+#             */
/*   Updated: 2023/07/27 19:41:59 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	strlen_2d(char **strs, int size)
{
	int	i;
	int	j;
	int	count;


	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			count++;
		}
		i++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] && i < size)
		i++;
	j = 0;
	if (i < size)
	{
		while (src[j] && i < size - 1)
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	while (src[j])
	{
		j++;
		i++;
	}
	return (i);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		len;
	int		i;
	if (size == 0 || strs == NULL || sep == NULL)
	{
		result = (char *)malloc(sizeof(char));
		if (result == NULL)
			return (NULL);
		result[0] = 0;
		return (result);
	}
	len = strlen_2d(strs, size) + ((size - 1) * ft_strlen(sep)) + 1;
	result = (char *)malloc(len * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strlcat(result, strs[i], len);
		ft_strlcat(result, sep, len);
		i++;
	}
	return(result);
}
