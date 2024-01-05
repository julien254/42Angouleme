/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:35:41 by julien            #+#    #+#             */
/*   Updated: 2024/01/05 15:48:07 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_fd(int fd, t_list *filed)
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

char	*ft_save_residu(t_list *filed, char *ligne)
{
	int	i;
	int	j;

	i = 0;
	if (!ligne[i])
		return (NULL);
	while (ligne[i] != '\n' && ligne[i])
		i++;
	if (ligne[i])
		i++;
	j = 0;
	while (ligne[i])
	{
		filed->save.residu[filed->save.index_currentfd][j] = ligne[i];
		ligne[i] = 0;
		i++;
		j++;
	}
	filed->save.residu[filed->save.index_currentfd][j] = 0;
	if (j == 0)
		ft_memset(filed->save.residu[filed->save.index_currentfd]);
	ft_memset(filed->residu);
	return (ligne);
}

char	*ft_split_and_save(t_list *filed)
{
	int		i;
	int		j;
	char	*ligne;

	ligne = (char *)malloc(end_line(filed->residu) + 2);
	if (!ligne)
		return (ligne);
	i = 0;
	while (filed->residu[i] != '\n')
	{
		ligne[i] = filed->residu[i];
		i++;
	}
	ligne[i++] = '\n';
	ligne[i] = 0;
	j = 0;
	if (filed->residu[i] == 0)
		ft_memset(filed->save.residu[filed->save.index_currentfd]);
	while (filed->residu[i])
		filed->save.residu[filed->save.index_currentfd][j++] \
				= filed->residu[i++];
	filed->save.residu[filed->save.index_currentfd][j] = 0;
	return (ligne);
}

char	*ft_readbuf(t_list *filed)
{
	char	*str_read;
	int		reader;

	str_read = (char *)malloc(BUFFER_SIZE + 1);
	if (!str_read)
		return (str_read);
	reader = read(filed->fd, str_read, BUFFER_SIZE);
	str_read[reader] = 0;
	if (reader == 0)
		filed->save.is_finish[filed->save.index_currentfd] = 1;
	return (str_read);
}

char	*get_next_line(int fd)
{
	static t_list	filed = {0, {0}, {{0}, {""}, {0}, 0}};
	char			*str_read;
	char			*ligne;

	if (read(fd, "", 0) == -1)
		return (NULL);
	check_fd(fd, &filed);
	if (end_line(filed.residu))
		return (ft_split_and_save(&filed));
	if (filed.save.is_finish[filed.save.index_currentfd])
		return (NULL);
	ligne = (char *)malloc(BUFFER_SIZE + 1);
	ft_strcpy(filed.save.residu[filed.save.index_currentfd], ligne);
	while (!end_line(ligne) && \
			!filed.save.is_finish[filed.save.index_currentfd])
	{
		str_read = ft_readbuf(&filed);
		ligne = ft_strjoin(ligne, str_read, &filed);
		if (!ligne)
		{
			free(str_read);
			return (NULL);
		}
	}
	return (ft_save_residu(&filed, ligne));
}
