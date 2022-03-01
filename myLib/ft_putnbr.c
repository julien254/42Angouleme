#include "lib.h"

void ft_putnbr(int nbr)
{
	if (nbr <= MAX_INT && nbr >= MIN_INT)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr < 10)
			ft_putchar('0' + nbr);
		else
		{
			ft_putnbr(nbr / 10);
			ft_putchar('0' + (nbr % 10));
		}
	}
}