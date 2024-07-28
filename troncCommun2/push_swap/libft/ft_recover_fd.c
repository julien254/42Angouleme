/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recover_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:16:55 by julien            #+#    #+#             */
/*   Updated: 2024/07/09 13:50:04 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rm_return_line(char *str)
{
	while (*str != '\n' && *str)
		str++;
	*str = 0;
}

char	**ft_recover_fd(char *file)
{
	int		fd;
	char	**fd_2d;
	size_t	i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	fd_2d = malloc(sizeof(char *) * 1);
	if (!fd_2d)
		return (NULL);
	i = 0;
	fd_2d[i] = get_next_line(fd);
	rm_return_line(fd_2d[i]);
	while (fd_2d[i])
	{
		fd_2d = ft_realloc(fd_2d, sizeof(char *) * (1 + i), sizeof(char *) * \
																(1 + i + 1));
		if (!fd_2d)
			return (NULL);
		i++;
		fd_2d[i] = get_next_line(fd);
		if (fd_2d[i])
			rm_return_line(fd_2d[i]);
	}
	return (fd_2d);
}
