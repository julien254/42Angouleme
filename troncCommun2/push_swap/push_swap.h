/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:14:22 by jdetre            #+#    #+#             */
/*   Updated: 2024/08/02 10:16:55 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

# define ERROR_MALLOC 1
# define STR_MALLOC "Error\n"
# define ERROR_ARGV 2
# define STR_ARGV "Error\n"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

/************************ INSTRUCTIONS *************************/

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	ra(t_stack **stack_a);
void	rra(t_stack **stack_a);

/************************ MOVES *************************/

void	push(t_stack **stack_src, t_stack **stack_dst);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
void	swap(t_stack **stack);

/************************ STACK_UTILS *************************/

t_stack	*stack_last(t_stack *stack);
t_stack	*stack_before_last(t_stack *stack);
int		stack_size(t_stack *stack);
int		index_min(t_stack **stack);
void	free_stack(t_stack *stack);

/************************ BIT_UTILS *************************/

int		max_bit(t_stack *stack);

/************************ SORT *************************/

void	radix(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b);
int		if_sorted(t_stack *stack);

/************************ LST_STACK *************************/

t_stack	*stack_new(int nbr);
void	stack_add_back(t_stack **stack, int nbr);
void	make_stack_elem(t_stack **stack_a, char *str);
void	make_stack_a(t_stack **stack_a, char **argv);

/************************ UTILS *************************/

int		if_sorted(t_stack *stack);
void	exit_failure(t_stack **stack_a, int error, char **arg);
int		check_is_nbr(char *str);

/************************ NORMALIZE *************************/

int		search_index(t_stack *stack_a, int value);
void	make_order_index(t_stack **stack_a);

#endif /* ifndef PUSH_SWAP_H */
