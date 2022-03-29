/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:51:14 by jdetre            #+#    #+#             */
/*   Updated: 2022/03/03 23:34:22 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "biblio.h"

char	*ft_recup_map(char *map)
{
	/*fonction de merde !*/
	int		fd;
	char	*str;

	str = malloc(sizeof(*str) * 100000);
	if (str == NULL)
	{
		ft_putstr("Error Allocation");
		return(NULL);
	}
	else
	{
		ft_init_str(str);
		fd = open(map, O_RDONLY);
		if (fd == -1)
			ft_putstr("open() failed\n");
		read(fd, str, 100000);
		close(fd);
		return (str);
	}
}
