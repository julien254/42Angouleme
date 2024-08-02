/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:05:44 by judetre           #+#    #+#             */
/*   Updated: 2024/08/02 10:06:24 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	search_index(t_stack *stack_a, int value)
{
	int		count;
	int		index;
	t_stack	*stack;

	count = 0;
	index = 0;
	stack = stack_a;
	while (stack)
	{
		if (stack->value < value)
			index++;
		if (stack->value == value)
			count++;
		if (count == 2)
			exit_failure(&stack_a, ERROR_ARGV, NULL);
		stack = stack->next;
	}
	return (index);
}

void	make_order_index(t_stack **stack_a)
{
	t_stack	*stack;

	stack = *stack_a;
	while (stack)
	{
		stack->index = search_index(*stack_a, stack->value);
		stack = stack->next;
	}
}
