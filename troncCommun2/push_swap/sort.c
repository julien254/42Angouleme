/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:03:56 by jdetre            #+#    #+#             */
/*   Updated: 2024/07/27 14:15:16 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		size_max_bit;

	i = 0;
	size_max_bit = max_bit(*stack_a);
	while (i < size_max_bit)
	{
		j = 0;
		size = stack_size(*stack_a);
		while (j < size)
		{
			if ((*stack_a)->index >> i & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_size(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	//int	size;

	if (if_sorted(*stack_a) == 0)
	{
		//size = stack_size(*stack_a);
		//if (size == 2)
		//	ra(stack_a);
		//else if (size == 3)
		//	sort_3(stack_a);
		//else if (size == 4)
		//	sort_4(stack_a, stack_b);
		//else if (size == 5)
		//	sort_5(stack_a, stack_b);
		//else
		radix(stack_a, stack_b);
	}
}
