/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:30:06 by julien            #+#    #+#             */
/*   Updated: 2022/07/02 02:24:33 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd[4];
	char	*str;

	(void)argc;
	(void)argv;

	fd[0] = open("files/1", O_RDWR);
	fd[1] = open("files/2", O_RDWR);
	fd[2] = open("files/3", O_RDWR);
	printf("%s", str = get_next_line(fd[0]));
	free(str);

	printf("%s", str = get_next_line(fd[0]));
	free(str);
	printf("%s", str = get_next_line(fd[1]));
	free(str);
	printf("%s", str = get_next_line(fd[1]));
	free(str);
	printf("%s", str = get_next_line(fd[0]));
	free(str);
	printf("%s", str = get_next_line(fd[1]));
	free(str);
	printf("%s", str = get_next_line(fd[2]));
	free(str);
	printf("%s", str = get_next_line(fd[0]));
	free(str);

	return (0);
}
