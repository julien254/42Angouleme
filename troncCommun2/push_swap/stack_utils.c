/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:58:37 by jdetre            #+#    #+#             */
/*   Updated: 2024/07/27 13:11:50 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int     stack_size(t_stack *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack *stack_before_last(t_stack *stack)
{
	int	size;
	int	i;

	size = stack_size(stack);
	if (size < 2)
		return (NULL);
	i = 1;
	while (i < size - 1)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}
