/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:41:17 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/31 19:30:52 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	d;

	i = 1;
	j = 0;
	if (argc > 1)
	{
		while (i < argc)
		{
			i = 0;
			while (argv[i][j] != '\0')
			{
				write(1, &argv[i][j], 1);
				d++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
