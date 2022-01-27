#include <unistd.h>

void	ft_putstr_non_printable(int nbr, char *hexadecimal)
{
	if (nbr < 16)
		write(1, &hexadecimal[nbr], 1);
	else
	{
		ft_putstr_non_printable(nbr / 16, hexadecimal);
		write(1, &hexadecimal[nbr % 16], 1);
	}
}

int main()
{
	char    *hexadecimal;

        hexadecimal = "0123456789abcdef";
	ft_putstr_non_printable(1846738, hexadecimal);
}
