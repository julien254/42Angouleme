/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:34:33 by judetre           #+#    #+#             */
/*   Updated: 2023/07/31 19:00:08 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long int	size;
	int				*array;
	long long int	i;

	size = (long long int)max - (long long int)min;
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	*range = array;
	return ((int)size);
}
