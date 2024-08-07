/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:38:34 by judetre           #+#    #+#             */
/*   Updated: 2024/08/06 11:29:57 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
int is_prime(int nbr)
{
	int i = 2;

	if (nbr <= 1)
		return (0);
	while (i <= nbr / 2)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	return_prime(int index)
{
	int nbr;
	int i;

	nbr = 0;
	i = 0;
	while (1) 
	{
		if (is_prime(nbr))
			i++;
		if (i == index)
			return (nbr);
		nbr++;
	}
}

int	main(int argc, char *argv[])
{
	int nbr;
	int i;
	int factor;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	nbr = atoi(argv[1]);
	if (nbr <= 0)
	{
		printf("\n");
		return (0);
	}	
	if (nbr == 1)
		printf("1\n");
	else if (is_prime(nbr))
		printf("%d\n", nbr);
	else
	{
		i = 1;
		while (nbr != 1)
		{
			factor = return_prime(i);
			while (nbr % factor == 0)
			{
				printf("%d", factor);
				nbr /= factor;
				if (nbr == 1)
					printf("\n");
				else
					printf("*");
			}
			i++;
		}
	}

	return (0);
} 
