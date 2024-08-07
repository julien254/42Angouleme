/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 05:46:16 by judetre           #+#    #+#             */
/*   Updated: 2024/08/07 07:06:12 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int nbr_len(int nbr)
{
	int size;

	size = 0;
	while (nbr > 10)
	{
		nbr /= 10;
		size++;
	}
	size++;
	return (size);
}

void	itoa_recursive(char *result, int size, int nbr, int isneg)
{
	if (size == 0)
		return;
	itoa_recursive(result, size - 1, nbr/ 10, isneg);
	result[size - 1 + isneg] = nbr % 10 + '0';
}

char	*ft_itoa(int nbr)
{
	int isneg = 0;
	int	size;
	long int nb = nbr;
	char *result;

	if (nb < 0)
	{
		isneg = 1;
		nb = -nb;
	}
	size = nbr_len(nb);
	result = (char *)malloc(sizeof(char) * (size + isneg + 1));
	if (isneg)
		result[0] = '-';
	itoa_recursive(result, size, nb, isneg);
	result[size + isneg + 1] = '\0';
	return (result);

}

/* int	main(int argc, char *argv[]) */
/* { */
/* 	(void)argc; */
/* 	printf("%s\n", ft_itoa(atoi(argv[1]))); */
/* 	return (0); */
/* } */
