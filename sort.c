/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:00:58 by eplouzen          #+#    #+#             */
/*   Updated: 2024/02/24 00:21:54 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	if (((*stack_a)->index < (*stack_a)->next->index) && \
		((*stack_a)->index < (*stack_a)->next->next->index))
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (((*stack_a)->index > (*stack_a)->next->index) && \
		((*stack_a)->index > (*stack_a)->next->next->index))
	{
		if ((*stack_a)->next->index > (*stack_a)->next->next->index)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else if ((*stack_a)->next->index < (*stack_a)->next->next->index)
			ra(stack_a);
	}
	else
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		else if ((*stack_a)->index < (*stack_a)->next->index)
			rra(stack_a);
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	min_index = get_index(*stack_a, get_min(*stack_a));
	if (min_index == 1)
		sa(stack_a);
	if (min_index == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (min_index == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	if (ft_check_sorted(*stack_a) == 0)
		sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	min_index = get_index(*stack_a, get_min(*stack_a));
	if (min_index == 1)
		sa(stack_a);
	if (min_index == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (min_index == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (min_index == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	if (ft_check_sorted(*stack_a) == 0)
		sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_radix(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		len_stack_a;
	int		max_bit;

	i = 0;
	max_bit = stack_max_bit(*stack_a);
	while (i < max_bit)
	{
		j = 0;
		len_stack_a = stack_count(*stack_a);
		while (j < len_stack_a)
		{
			if ((*stack_a)->index >> i & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_count(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

void	sort_x(t_list **stack_a, t_list **stack_b)
{
	int	len_stack_a;

	if (ft_check_sorted(*stack_a) == 0)
	{
		len_stack_a = stack_count(*stack_a);
		if (len_stack_a == 2)
			ra(stack_a);
		else if (len_stack_a == 3)
			sort_3(stack_a);
		else if (len_stack_a == 4)
			sort_4(stack_a, stack_b);
		else if (len_stack_a == 5)
			sort_5(stack_a, stack_b);
		else
			sort_radix(stack_a, stack_b);
	}
}
