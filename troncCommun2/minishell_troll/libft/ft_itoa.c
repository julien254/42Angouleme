/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:54:28 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/08 18:03:03 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_sizen(int n)
{
	int	i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;
	int		value;

	if (n == -2147483647 - 1)
		return (ft_strdup("-2147483648"));
	size = ft_sizen(n);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	value = ft_abs(n);
	str[size] = '\0';
	size--;
	while (size != -1)
	{
		str[size] = value % 10 + '0';
		value /= 10;
		size--;
	}
	if (n < 0)
	{
		size++;
		str[size] = '-';
	}
	return (str);
}
