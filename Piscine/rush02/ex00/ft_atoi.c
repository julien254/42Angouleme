/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:26:35 by cmieuzet          #+#    #+#             */
/*   Updated: 2023/07/29 15:50:58 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "biblio.h"

unsigned long long int	ft_atoi(char *str)
{
	unsigned long long int	nb;	
	unsigned long long int	i;

	i = 0;
	nb = 0;
	while (str[i] <= 32 )
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
//	if (nb <= 4294967295)
		return (nb);
	return (0);
}
