/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:54:08 by judetre           #+#    #+#             */
/*   Updated: 2024/08/02 10:32:02 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*stack_new(int nbr)
{
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		exit_failure(&stack, ERROR_MALLOC, NULL);
	stack->value = nbr;
	stack->next = NULL;
	return (stack);
}

void	stack_add_back(t_stack **stack, int nbr)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = stack_new(nbr);
		return ;
	}
	last = stack_last(*stack);
	last->next = stack_new(nbr);
}

void	make_stack_elem(t_stack **stack_a, char *str)
{
	long int	nbr;
	char		**arg;
	int			i;

	i = 0;
	arg = ft_split(str, ' ');
	if (!*arg)
		exit_failure(stack_a, ERROR_MALLOC, arg);
	while (arg[i])
	{
		if (check_is_nbr(arg[i]))
			exit_failure(stack_a, ERROR_ARGV, arg);
		nbr = ft_atol(arg[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			exit_failure(stack_a, ERROR_ARGV, arg);
		stack_add_back(stack_a, nbr);
		i++;
	}
	ft_free_malloc2d((void *)arg);
}

void	make_stack_a(t_stack **stack_a, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		make_stack_elem(stack_a, argv[i]);
		i++;
	}
	make_order_index(stack_a);
}
