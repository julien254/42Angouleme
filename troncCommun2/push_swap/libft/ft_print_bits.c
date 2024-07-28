/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:34:54 by jdetre            #+#    #+#             */
/*   Updated: 2024/07/27 11:07:35 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_print_bits(long int nbr)
{
	int		bits; 
	char	*binary;
	int		index;

	bits = ft_bitlen(nbr);
	binary = (char *)malloc(bits + 1);
	if (binary == NULL)
	{
		perror("Error allocate memory");
		return (NULL);
	}
	binary[bits] = '\0';
	index = bits - 1;
	while (index >= 0)
	{
		if (nbr & 1)
			binary[index] = '1';
		else
			binary[index] = '0';
		nbr >>= 1;
		index--;
	}
	return (binary);
}
