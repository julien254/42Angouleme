/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:35:41 by julien            #+#    #+#             */
/*   Updated: 2022/04/23 13:52:41 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	check_fd(int fd, t_list *filed)
{
	int	i;
	int	j;

	i = 0;
	while (filed->save.fd[i] != fd && filed->save.fd[i] != 0)
		i++;
	if (filed->save.fd[i] != fd)
	{
		filed->fd = fd;
		filed->save.fd[i] = fd;
		filed->save.index_currentfd = i;
		filed->residu[0] = 0;
	}
	else
	{
		j = 0;
		filed->fd = fd;
		filed->save.index_currentfd = i;
		while (filed->save.residu[i][j])
		{
			filed->residu[j] = filed->save.residu[i][j];
			j++;
		}
		filed->residu[j] = 0;
	}
}

static char	*ft_setbuf(char *str_read, t_list *filed, int *reader, int *boo)
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

static char	*ft_split_str(int reader, char *str_read, int *boo, t_list *filed)
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
	static t_list	filed = {0, {0}, "", {{0}, {""}, 0}};
	char			*ltemp;
	int				boo;

	if (fd != filed.fd)
		check_fd(fd, &filed);
	if (read(filed.fd, filed.ligne, 0) == -1)
		return (NULL);
	filed.ligne = "";
	if (filed.residu[0] != 0)
	{
		filed.ligne = ft_strdup(filed.residu, '\0');
		filed.residu[0] = 0;
		/* filed.save.residu[filed.save.index_currentfd][0] = 0; */
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
