/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:51:58 by judetre           #+#    #+#             */
/*   Updated: 2023/07/25 16:36:50 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>

int *ft_range(int min, int max)
{
	long long int	size;
	int	*array;
	long long int	i;

	size = (long long int)max - (long long int)min;
	if (size < 0)
		return (NULL);
	array = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}
