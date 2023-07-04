/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:00:18 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/04 13:24:40 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main test for c04 */
#include "../piscine.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_putnbr(ft_atoi("\n \v \f \r \t -+--324332f324"));

	ft_putchar('\n');
	ft_putchar('\n');

	ft_putnbr_base(-123456, "0123456789ABCDEF");
}
