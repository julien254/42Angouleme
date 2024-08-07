/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:58:14 by jdetre            #+#    #+#             */
/*   Updated: 2024/08/04 16:04:25 by judetre          ###   ########.fr       */
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

int	fnctl_de_merde(void)
{
	return (1);
}
