/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:17:42 by judetre           #+#    #+#             */
/*   Updated: 2023/07/19 18:54:19 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (nb < 0)
		return (0);
	if (nb > 1)
		ft_recursive(nb, &result);
	return (result);
}
