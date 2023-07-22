/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:48:19 by judetre           #+#    #+#             */
/*   Updated: 2023/07/19 09:25:18 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (nb == 0 && power == 0)
		return (result);
	else if (power < 0)
		return (0);
	while (power)
	{
		result *= nb;
		power--;
	}
	return (result);
}
