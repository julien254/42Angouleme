/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:53:47 by jdetre            #+#    #+#             */
/*   Updated: 2024/10/23 15:35:52 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_strcat(char *src, char *dest)
{
	int i;
	int i_dest;

	i_dest = 0;
	while (dest[i_dest])
		i_dest++;
	i = 0;
	while (src[i])
	{
		dest[i_dest] = src[i];
		i++;
		i_dest++;
	}
	dest[i_dest] = 0;
}

int if_backslash_n(char *residu)
{
	int i;

	i = 0;
	while (residu && residu[i])
	{
		if (residu[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int ft_size_line(char *residu)
{
	int i;

	i = 0;
	while (residu[i] && residu[i] != '\n')
		i++;
	return (i);
}

char *get_residu(char **residu)
{
	int i;
	int i_new_residu;
	char *new_residu;
	char *line;
	int size_line;

	if (!(*residu))
		return (NULL);
	size_line = ft_size_line(*residu) + 2;
	line = (char *)malloc(size_line * sizeof(char));
	i = 0;
	while ((*residu)[i] && (*residu)[i] != '\n' )
	{
		line[i] = (*residu)[i];
		i++;
	}
	if ((*residu)[i] == '\n')
	{
		line[i++] = '\n';
		line[i] = 0;
	}
	else
		line[i] = 0;
	if ((*residu)[i])
	{
		new_residu = (char *)malloc(sizeof(char) * 10000000);
		if (!new_residu)
		{
			free(line);
			return (NULL);
		}
		i_new_residu = 0;
		while ((*residu)[i])
		{
			new_residu[i_new_residu] = (*residu)[i];
			i++;
			i_new_residu++;
		}
		new_residu[i_new_residu] = 0;
		free(*residu);
		*residu = new_residu;
	}
	else
	{
		free(*residu);
		*residu = NULL;
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char *residu = NULL;
	static int read_size = 1;
	char *line;
	char buffer_read[BUFFER_SIZE + 1];

	buffer_read[0] = 0;
	while (!if_backslash_n(residu) && read_size != 0)
	{
		read_size = read(fd, buffer_read, BUFFER_SIZE);
		if (read_size == -1)
			return (NULL);
		buffer_read[read_size] = 0;
		if (!residu)
		{
			residu = (char *)malloc(sizeof(char) * 10000000);
			if (!residu)
				return (NULL);
			residu[0] = 0;
		}
		ft_strcat(buffer_read, residu);
	}
	line = get_residu(&residu);
	return (line);
}

/* int main(void) */
/* { */
/* 	int fd; */
/* 	char *line; */
/* 	fd = open("test", O_RDONLY); */
/* 	line = get_next_line(fd); */
/* 	printf("%s", line); */
/* 	while (line) */
/* 	{ */
/* 		free(line); */
/* 		line = get_next_line(fd); */
/* 		printf("%s", line); */
/* 	} */
/* 	return (0); */
/* } */
