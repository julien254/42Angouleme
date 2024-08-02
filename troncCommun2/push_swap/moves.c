/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:45:16 by jdetre            #+#    #+#             */
/*   Updated: 2024/08/02 10:12:33 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || stack_size(*stack) == 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = stack_last(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack)
		return ;
	last = stack_last(*stack);
	before_last = stack_before_last(*stack);
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	swap(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	tmp2 = tmp->next;
	tmp->next = *stack;
	(tmp->next)->next = tmp2;
	*stack = tmp;
}
