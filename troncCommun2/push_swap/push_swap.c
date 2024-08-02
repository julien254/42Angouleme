/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:02:28 by jdetre            #+#    #+#             */
/*   Updated: 2024/08/02 07:47:12 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack *temp;
	t_stack *current;

	current = stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

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

void	print_stack(t_stack *stack)
{
	int index;

	index = 1;
	if (!stack)
		ft_putstr_fd("NULL\n", 1);
	while (stack)
	{
		ft_printf("Elem %d: ", index++);
		ft_putnbr_fd(stack->value, 1);
		ft_putstr_fd(" order = ", 1);
		ft_putnbr_fd(stack->index, 1);
		ft_putstr_fd("\n", 1);
		stack = stack->next;
	}
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n", 1);
}

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

t_stack	*stack_last(t_stack *stack)
{
	while (stack)
	{
		if (stack->next == NULL)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

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

void stack_add_back(t_stack **stack, int nbr)
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

void	make_stack_elem(t_stack **stack_a, char *str)
{
	long int	nbr;
	char		**arg;
	int			i;

	i = 0;
	arg = ft_split(str, ' ');
	if (!*arg)
		exit_failure(stack_a, ERROR_MALLOC, NULL);
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void)stack_b;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit_failure(NULL, ERROR_ARGV, NULL);
	make_stack_a(&stack_a, argv);
	//print_stack(stack_a);
	//print_stack(stack_b);
	sort(&stack_a, &stack_b);
	//print_stack(stack_a);
	//print_stack(stack_b);
	free_stack(stack_a);
	return (0);
}
