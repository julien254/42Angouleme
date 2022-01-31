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
int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

int main(void)
{
	printf("%d", ft_recursive_power(2, 3));
}
