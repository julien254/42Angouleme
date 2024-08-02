/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:03:56 by jdetre            #+#    #+#             */
/*   Updated: 2024/08/02 08:23:47 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
void	sort_3_elem(t_stack **stack)
{
	int min;

	min = index_min(stack);
	if (min == 0)
	{
		rra(stack);
		sa(stack);
	}
	if (min == 1)
	{
		if ((*stack)->index < (*stack)->next->next->index)
			sa(stack);
		else
			ra(stack);
	}
	if (min == 2)
	{
		if ((*stack)->index < (*stack)->next->index)
			rra(stack);
		else
		{
			sa(stack);
			rra(stack);
		}
	}
}

void	sort_4_elem(t_stack **stack_a, t_stack **stack_b)
{
	int min;

	min = index_min(stack_a);
	if (min == 1)
		sa(stack_a);
	if (min == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (min == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	if (if_sorted(*stack_a) == 0)
		sort_3_elem(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5_elem(t_stack **stack_a, t_stack **stack_b)
{
	int min;

	min = index_min(stack_a);
	if (min == 1)
		sa(stack_a);
	if (min == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (min == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (min == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	if (if_sorted(*stack_a) == 0)
		sort_4_elem(stack_a, stack_b);
	pa(stack_a, stack_b);
}

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
	int	size;

	if (if_sorted(*stack_a) == 0)
	{
		size = stack_size(*stack_a);
		if (size == 2)
			sa(stack_a);
		else if (size == 3)
			sort_3_elem(stack_a);
		else if (size == 4)
			sort_4_elem(stack_a, stack_b);
		else if (size == 5)
			sort_5_elem(stack_a, stack_b);
		else
			radix(stack_a, stack_b);
	}
}
