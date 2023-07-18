/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:17:42 by judetre           #+#    #+#             */
/*   Updated: 2023/07/17 16:44:18 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
void	ft_recursive(int nb, int *result)
{
	if (nb == 1)
		*result *= nb;
	else
	{
		*result *= nb;
		ft_recursive(nb - 1, result);
	}
}

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb > 0)
		ft_recursive(nb, &result);
	return (result);
}


int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	printf("%d", ft_recursive_factorial(0));
	return (0);
}
