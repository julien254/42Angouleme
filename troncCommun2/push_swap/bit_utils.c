/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:58:14 by jdetre            #+#    #+#             */
/*   Updated: 2024/07/27 14:01:47 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	max_bit(t_stack *stack)
{
	int	max_bit;

	max_bit = 0;
	while (stack)
	{
		if (max_bit < ft_bitlen(stack->index))
			max_bit = ft_bitlen(stack->index);
		stack = stack->next;
	}
	return (max_bit);
}
