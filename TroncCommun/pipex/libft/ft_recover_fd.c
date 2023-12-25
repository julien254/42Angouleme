/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recover_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:16:55 by julien            #+#    #+#             */
/*   Updated: 2023/12/25 22:59:37 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_files(char *file, int OPTION_OK)
{
	if (access(file, OPTION_OK) != 0)
		return (1);
	else
		return (0);
}

int	check_files_infile(char *file)
{
	if (check_files(file, F_OK))
	{
		ft_printf("Aucun fichier ou dossier de ce type: %s", file);
		return (1);
	}
	if (check_files(file, R_OK))
	{
		ft_printf("Permission non accordee: %s", file);
		return (1);
	}
	return (0);
}

char	*ft_recover_fd(char *file)
{
	int		fd;
	char	*buffer;
	char	*buffertmp;
	char	*bufferfinal;

	bufferfinal = NULL;
	if (check_files_infile(file) == 0)
	{
		fd = open(file, O_RDONLY);
		buffer = get_next_line(fd);
		bufferfinal = ft_strdup(buffer);
		while (buffer)
		{
			free(buffer);
			buffer = get_next_line(fd);
			buffertmp = ft_strdup(buffer);
			if (buffertmp)
				bufferfinal = ft_strjoin_malloc(bufferfinal, buffertmp);
		}
		if (buffer)
			free(buffer);
	}
	return (bufferfinal);
}
