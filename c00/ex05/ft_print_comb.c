#include <unistd.h>

void ft_putchar(char c)
{
        write(1, &c, 1);
}

/* Function to control if the num is the last or not and call ft_putchar */
void ft_control_and_print(char a, char b , char c, char d)
{
	if ( a == '9' && b == '8' && c == '9' && d == '9')
	{                                        
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(' ');
		ft_putchar(c);
		ft_putchar(d);
	}
	else
	{
		ft_putchar(a);
                ft_putchar(b);
                ft_putchar(' ');
                ft_putchar(c);
                ft_putchar(d);
		ft_putchar(',');
		ft_putchar(' ');                
	}

}

void ft_print_comb(void)
{

}
int main(void)
{
	ft_putchar(49);
}
