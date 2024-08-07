/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:12:26 by judetre           #+#    #+#             */
/*   Updated: 2024/08/06 09:19:49 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	int nbr;
	int nbr2;
	int result;

	if (argc != 4)
		printf("\n");
	else
	{
		nbr = atoi(argv[1]);
		nbr2 = atoi(argv[3]);
		if (argv[2][0] == '-')
		{
			printf("%d\n", nbr - nbr2);
		}
		if (argv[2][0] == '+')
		{
			printf("%d\n", nbr + nbr2);
		}
		if (argv[2][0] == '*')
		{
			printf("%d\n", nbr * nbr2);
		}
		if (argv[2][0] == '/')
		{
			printf("%d\n", nbr / nbr2);
		}
		if (argv[2][0] == '%')
		{
			printf("%d\n", nbr % nbr2);
		}
	}
	return (0);
}
