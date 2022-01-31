/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:41:17 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/31 13:51:27 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_iterative_power(int nb, int power)
{
	int n;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	n = nb - 1;
	while (power--)
		n *= nb;
	return (n);
}

int main(void)
{
	printf("%d", ft_iterative_power(0, 3));
}
