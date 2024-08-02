/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:01:12 by judetre           #+#    #+#             */
/*   Updated: 2024/08/02 10:01:55 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	if_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	exit_failure(t_stack **stack_a, int error, char **arg)
{
	ft_free_malloc2d((void *)arg);
	if (stack_a)
		free_stack(*stack_a);
	if (error == ERROR_MALLOC)
	{
		ft_putstr_fd(STR_MALLOC, 2);
		exit(ERROR_MALLOC);
	}
	if (error == ERROR_ARGV)
	{
		ft_putstr_fd(STR_ARGV, 2);
		exit(ERROR_ARGV);
	}
}

int	check_is_nbr(char *str)
{
	if ((*str == '+' || *str == '-') && *(str + 1) != 0)
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}
