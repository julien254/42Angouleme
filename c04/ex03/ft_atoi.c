/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:31:02 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/31 19:07:12 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	c;
	int	neg;
	int	result;

	c = 0;
	neg = 1;
	result = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	while (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			neg = neg * -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		result = (str[c] - '0') + (result * 10);
		c++;
	}
	return (result * neg);
}
