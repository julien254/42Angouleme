/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:17:42 by judetre           #+#    #+#             */
/*   Updated: 2023/07/17 16:34:57 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
int ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	while (nb > 1)
	{
		result *= nb;
		nb -= 1;
	}
	return (result);
}


int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	printf("%d", ft_iterative_factorial(5));
	return (0);
}
