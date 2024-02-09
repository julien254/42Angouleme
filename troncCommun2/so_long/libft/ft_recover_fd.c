/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recover_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:16:55 by julien            #+#    #+#             */
/*   Updated: 2024/02/09 21:49:33 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_recover_fd(char *file)
{
	int		fd;;
	char	**fd_2d;
	size_t	i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	fd_2d = malloc(sizeof(char *) * 1);
	i = 0;
	fd_2d[i] = get_next_line(fd);
	while (fd_2d[i])
	{
		fd_2d = ft_realloc(fd_2d, sizeof(char *) * (1 + i), sizeof(char *) * (1 + i + 1));
		i++;
		fd_2d[i] = get_next_line(fd);
	}
	return (fd_2d);
}
