/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:24:02 by jdetre            #+#    #+#             */
/*   Updated: 2023/12/11 18:07:50 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *buffer, int multiplier, t_save *save)
{
	char	*new_buffer;

	new_buffer = (char *)malloc((BUFFER_SIZE * multiplier) + \
												save->size_residue + 1);
	if (!new_buffer)
		return (NULL);
	new_buffer[0] = 0;
	if (save->residue != NULL)
	{
		ft_strlcat(new_buffer, save->residue);
		free(save->residue);
	}
	if (buffer)
	{
		ft_strlcat(new_buffer, buffer);
		free(buffer);
	}
	return (new_buffer);
}

char	*read_while_noendline(int fd, t_save *save)
{
	char	*buffer;
	char	*buffer_tmp;
	size_t	multiplier;

	multiplier = 0;
	buffer_tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer_tmp)
		return (NULL);
	buffer_tmp[0] = 0;
	buffer = 0;
	while (if_is_endline(buffer_tmp) != 1 && save->read_size != 0)
	{
		multiplier++;
		buffer = ft_realloc(buffer, multiplier, save);
		if (multiplier == 1)
			save->residue = NULL;
		save->read_size = read(fd, buffer_tmp, BUFFER_SIZE);
		if (save->read_size <= 0)
			return (free_all(buffer_tmp, buffer));
		buffer_tmp[save->read_size] = 0;
		ft_strlcat(buffer, buffer_tmp);
	}
	free(buffer_tmp);
	return (buffer);
}

char	*get_residue(char *line)
{
	int		i;
	char	*residue;

	i = 0;
	while (line[i] != '\n' && line[i] != 0)
		i++;
	if (line[i] == '\0' || ((line[i] == '\n') && (line[i + 1] == '\0')))
		return (NULL);
	residue = (char *)malloc((ft_strlen(line) - i));
	if (!residue)
		return (NULL);
	residue[0] = '\0';
	ft_strlcat(residue, line + i + 1);
	line[i + 1] = '\0';
	return (residue);
}

char	*get_next_line(int fd)
{
	static t_save	save = {NULL, 0, 1};
	char			*line;

	save.size_residue = ft_strlen(save.residue);
	if (save.residue && if_is_endline(save.residue))
	{
		line = ft_strdup(save.residue);
		free(save.residue);
		save.residue = get_residue(line);
	}
	else
	{
		line = read_while_noendline(fd, &save);
		if (line == NULL)
			return (NULL);
		save.residue = get_residue(line);
		if (save.read_size <= 0 && line[0] == 0)
			line = free_all(line, save.residue);
	}
	return (line);
}
