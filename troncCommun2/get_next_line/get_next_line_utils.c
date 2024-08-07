/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:24:02 by jdetre            #+#    #+#             */
/*   Updated: 2023/12/11 17:57:35 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strlcat(char *dst, char *src)
{
	size_t	i;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	i = dstlen;
	while (*src)
		dst[i++] = *(src++);
	dst[i] = '\0';
}

int	if_is_endline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(*str) * (ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*free_all(char *line, char *residue)
{
	free(line);
	if (residue)
		return (residue);
	free(residue);
	return (NULL);
}
