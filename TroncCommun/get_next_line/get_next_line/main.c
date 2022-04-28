/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:30:06 by julien            #+#    #+#             */
/*   Updated: 2022/04/28 12:42:22 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(int argc, char *argv[])
{
	int		fd[4];
	char	*str;
	int	i;

	(void)argc;
	(void)argv;

	fd[0] = open("files/1", O_RDWR);
	fd[1] = open("files/2", O_RDWR);
	fd[2] = open("files/3", O_RDWR);
	i = 0;
	while (i < 20)
	{
		printf("%s", str = get_next_line(fd[0]));
		printf("%s", str = get_next_line(fd[1]));
		printf("%s", str = get_next_line(fd[2]));
		i++;
	}
	return (0);

}
