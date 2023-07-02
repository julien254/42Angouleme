/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:00:18 by jdetre            #+#    #+#             */
/*   Updated: 2023/06/20 15:28:38 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main test for c01 */
#include "../piscine.h"


void	ft_putnbr(int nb)
{

	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr <= 9)
		ft_putchar('0' + nbr);
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar('0' + nbr % 10);
	}
}


void	ft_put_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		if (i == size - 1)
			ft_putchar('.');
		else
			ft_putchar(',');
		i++;
	}
	ft_putchar('\n');
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int	nbr;
	int	*ultimate1;
	int	**ultimate2;
	int	***ultimate3;
	int	****ultimate4;
	int	*****ultimate5;
	int	******ultimate6;
	int	*******ultimate7;
	int	********ultimate8;
	int	*********ultimate9;
	int	a;
	int	b;
	int	div;
	int	mod;
	int	tab[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	tab2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	tab_sort[12] = {-42, 3, -7, 19, 30, -1, 0, 6, 12, 10, 0, 1};

	ft_ft(&nbr);
	printf("%d\n", nbr);

	ultimate1 = &nbr;
	ultimate2 = &ultimate1;
	ultimate3 = &ultimate2;
	ultimate4 = &ultimate3;
	ultimate5 = &ultimate4;
	ultimate6 = &ultimate5;
	ultimate7 = &ultimate6;
	ultimate8 = &ultimate7;
	ultimate9 = &ultimate8;
	ft_ultimate_ft(ultimate9);
	printf("%d\n", *********ultimate9);

	ft_putchar('\n');
	ft_putchar('\n');

	a = 24;
	b = 42;
	printf("%d,%d\n",a ,b);
	ft_swap(&a , &b);
	printf("%d,%d\n",a ,b);

	ft_putchar('\n');
	ft_putchar('\n');

	ft_div_mod(5, 2, &div, &mod);
	printf("%d %d\n", div, mod);

	ft_putchar('\n');
	ft_putchar('\n');

	a = 5;
	b = 2;
	ft_ultimate_div_mod(&a, &b);
	printf("5 / 2 = %d, 5 %% 2 = %d\n", a, b);

	ft_putchar('\n');
	ft_putchar('\n');

	ft_putstr("je suis un boulet, mais il en faut, sinon on s'amuserai moin");

	ft_putchar('\n');
	ft_putchar('\n');

	printf("la longueur de la chaine est de : %d.\n", ft_strlen("cette chaine contient 35 caracteres"));

	ft_putchar('\n');
	ft_putchar('\n');

	ft_put_tab(tab, 9);
	ft_rev_int_tab(tab, 9);
	ft_put_tab(tab, 9);
	ft_put_tab(tab2, 10);
	ft_rev_int_tab(tab2, 10);
	ft_put_tab(tab2, 10);

	ft_putchar('\n');
	ft_putchar('\n');

	ft_put_tab(tab_sort, 12);
	ft_sort_int_tab(tab_sort, 12);
	ft_put_tab(tab_sort, 12);
	return (0);
}
