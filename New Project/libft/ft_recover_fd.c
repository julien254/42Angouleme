/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recover_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:16:55 by julien            #+#    #+#             */
/*   Updated: 2022/10/09 05:05:56 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_recover_fd(char *file)
{
	int		fd;
	char	*buffer;
	char	*buffertmp;
	char	*bufferfinal;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
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
	return (bufferfinal);
}
