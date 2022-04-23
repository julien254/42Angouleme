/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:30:06 by julien            #+#    #+#             */
/*   Updated: 2022/04/23 12:29:19 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	int		fd2;
	char	*str;

	(void)argc;
	(void)argv;
	fd = open("files/1.txt", O_RDWR);
	fd2 = open("files/2.txt", O_RDWR);
	printf("%s", str = get_next_line(fd));
	free(str);
	printf("%s", str = get_next_line(fd2));
	free(str);
	printf("%s", str = get_next_line(fd));
	free(str);
	printf("%s", str = get_next_line(fd2));
	free(str);
	printf("%s", str = get_next_line(fd));
	free(str);
	printf("%s", str = get_next_line(fd2));
	free(str);
	printf("%s", str = get_next_line(fd));
	free(str);
	printf("%s", str = get_next_line(fd2));
	free(str);
	printf("%s", str = get_next_line(fd));
	free(str);
	printf("%s", str = get_next_line(fd2));
	free(str);
	printf("%s", str = get_next_line(fd));
	return (0);
}
