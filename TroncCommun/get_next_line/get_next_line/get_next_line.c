/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:35:41 by julien            #+#    #+#             */
/*   Updated: 2022/04/23 07:52:18 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_setbuf(char *str_read, t_list *filed, int *reader, int *boo)
{
	if (*filed->ligne == '\n')
	{
		free(str_read);
		str_read = ft_strdup(filed->ligne, '\0');
		free(filed->ligne);
		filed->ligne = "";
		ft_strchr(str_read, filed);
		*boo = 0;
		return (str_read);
	}
	*reader = read(filed->fd, str_read, BUFFER_SIZE);
	str_read[*reader] = 0;
	if (*reader == 0)
	{
		free(str_read);
		str_read = ft_strdup(filed->ligne, '\0');
		if (*filed->ligne != 0)
			free(filed->ligne);
		filed->ligne = "";
		*boo = 2;
		return (str_read);
	}
	return (str_read);
}

char	*ft_split_str(int reader, char *str_read, int *boo, t_list *filed)
{
	int	i;

	if (reader == 0 && *str_read == 0)
	{
		free(str_read);
		return (NULL);
	}
	i = 0;
	while (str_read[i])
	{
		if (str_read[i] == '\n')
		{
			*boo = 0;
			ft_strchr(str_read, filed);
			return (str_read);
		}
		i++;
	}
	return (str_read);
}

static char	*ft_readbuf(t_list *filed, int *boo)
{
	char	*str_read;
	int		reader;
	char	*result;

	str_read = (char *)malloc(BUFFER_SIZE + 1);
	if (!str_read)
		return (NULL);
	result = ft_setbuf(str_read, filed, &reader, boo);
	if (result && *boo == 0)
	{
		str_read = result;
		return (str_read);
	}
	else if (result && *boo == 2)
	{
		str_read = result;
		*boo = 0;
	}
	result = ft_split_str(reader, str_read, boo, filed);
	if (result)
	{
		str_read = result;
		return (str_read);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	filed = {0, {0}, "", NULL};
	char			*ltemp;
	int				boo;

	if (read(fd, filed.ligne, 0) == -1)
		return (NULL);
	filed.ligne = "";
	if (!filed.fd)
		filed.fd = fd;
	if (filed.residu[0] != 0)
	{
		filed.ligne = ft_strdup(filed.residu, '\0');
		filed.residu[0] = 0;
	}
	boo = 1;
	while (boo)
	{
		ltemp = ft_readbuf(&filed, &boo);
		if (!ltemp)
			return (NULL);
		filed.ligne = ft_strjoin(filed.ligne, ltemp);
	}
	return (filed.ligne);
}
