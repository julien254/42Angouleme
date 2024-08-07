/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:21:09 by judetre           #+#    #+#             */
/*   Updated: 2024/08/06 09:36:10 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	int nbr;
	int nbr2;
	int denominator;

	if (argc != 3)
		printf("\n");
	else
	{
		nbr = atoi(argv[1]);
		nbr2 = atoi(argv[2]);
		if (nbr < nbr2)
			denominator = nbr;
		else
			denominator = nbr2;
		while (denominator != 0)
		{
			if (nbr % denominator == 0 && nbr2 % denominator == 0)
			{
				printf("%d\n", denominator);
				return (0);
			}
			denominator--;
		}

	}
	
	return (0);
}
