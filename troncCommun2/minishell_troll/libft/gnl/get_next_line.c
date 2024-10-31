/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:23:26 by uguidoni          #+#    #+#             */
/*   Updated: 2024/03/27 21:53:07 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, int check, char *buffer, char *str)
{
	while (gnl_ft_strchr(str, '\n') == 0)
	{
		buffer = gnl_ft_calloc(1, BUFFER_SIZE + 1);
		if (!buffer)
			free(str);
		if (!buffer)
			return (NULL);
		check = read(fd, buffer, BUFFER_SIZE);
		if (check < 0)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[check] = '\0';
		str = gnl_ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		if (check < BUFFER_SIZE)
			free(buffer);
		if (check < BUFFER_SIZE)
			return (str);
		free(buffer);
	}
	return (str);
}

char	*ft_gnl_check(int fd, char *str)
{
	char	*buffer;
	int		check;

	if (!str)
	{
		str = gnl_ft_calloc(1, 1);
		if (!str)
			return (NULL);
	}
	buffer = NULL;
	check = 0;
	str = ft_read(fd, check, buffer, str);
	return (str);
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	line = gnl_ft_calloc(1, i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_stash(char *stash)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	while (stash[i + j] != '\0')
		j++;
	str = gnl_ft_calloc(1, j + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (stash[i] != '\0')
		str[j++] = stash[i++];
	free(stash);
	stash = gnl_ft_strdup(str);
	free(str);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || (fd < 0 && fd <= 1024))
		return (NULL);
	if (!stash)
		stash = ft_gnl_check(fd, NULL);
	else
		stash = ft_gnl_check(fd, stash);
	line = ft_line(stash);
	if (!line)
		return (NULL);
	stash = ft_stash(stash);
	if (!stash)
		free(line);
	if (!stash)
		return (NULL);
	if (!*line)
	{
		free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
