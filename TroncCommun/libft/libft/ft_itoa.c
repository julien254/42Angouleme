/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:56:25 by julien            #+#    #+#             */
/*   Updated: 2022/04/11 23:04:05 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static void	strrev(char *str)
{
	size_t	i;
	size_t	size;
	char	tmp;

	size = ft_strlen(str);
	i = 0;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i++ - 1] = tmp;
	}
}

char	*ft_itoa(int n)
{
	char		*nbr;
	int			isneg;
	size_t		i;

	isneg = (n < 0);
	nbr = (char *)ft_calloc(11 + isneg, 1);
	if (!nbr)
		return (NULL);
	if (n == 0)
		nbr[0] = '0';
	i = 0;
	while (n != 0)
	{
		nbr[i++] = '0' + ft_abs(n % 10);
		n = n / 10;
	}
	if (isneg)
		nbr[i] = '-';
	strrev(nbr);
	return (nbr);
}
