/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:00:18 by jdetre            #+#    #+#             */
/*   Updated: 2023/06/18 19:40:57 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main test for c00 */
#include "../piscine.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_putchar('c');
	ft_putchar('\n');
	ft_print_alphabet();
	ft_putchar('\n');
	ft_print_reverse_alphabet();
	ft_putchar('\n');
	ft_print_numbers();
	ft_putchar('\n');
	ft_is_negative(0);
	ft_is_negative(2);
	ft_is_negative(4324);
	ft_is_negative(-1);
	ft_is_negative(-32);
	ft_is_negative(-421432);
	ft_putchar('\n');
	ft_print_comb();
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_comb2();
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putnbr(9);
	ft_putchar('\n');
	ft_putnbr(1234567);
	ft_putchar('\n');
	ft_putnbr(7891234);
	ft_putchar('\n');
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(123321);
	ft_putchar('\n');
	ft_putnbr(-1234);
	ft_putchar('\n');
	ft_putnbr(INT_MAX);
	ft_putchar('\n');
	ft_putnbr(-2147483647);
	ft_putchar('\n');
	ft_putnbr(INT_MIN);
	ft_putchar('\n');
	ft_print_combn(4);
	return (0);
}
