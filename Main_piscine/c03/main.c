/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:00:18 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/04 08:32:33 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main test for c03 */
#include "../piscine.h"


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}


void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb <= 9)
	{
		ft_putchar('0' + nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar('0' + nb % 10);
	}
}


int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char	dest[100];

	ft_putnbr(ft_strcmp("hello","hello"));
	ft_putchar('\n');
	ft_putnbr(strcmp("hello", "hello"));
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putnbr(ft_strcmp("",""));
	ft_putchar('\n');
	ft_putnbr(strcmp("", ""));
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putnbr(ft_strcmp("Hello","E"));
	ft_putchar('\n');
	ft_putnbr(strcmp("Hello", "E"));
	ft_putchar('\n');
	ft_putchar('\n');


	ft_putnbr(ft_strncmp("hello","hello", 3));
	ft_putchar('\n');
	ft_putnbr(strncmp("hello", "hello", 3));
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putnbr(ft_strncmp("","", 3));
	ft_putchar('\n');
	ft_putnbr(strncmp("", "", 3));
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putnbr(ft_strncmp("Hello","", 3));
	ft_putchar('\n');
	ft_putnbr(strncmp("Hello", "", 3));
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putnbr(ft_strncmp("Hello","Heloo", 3));
	ft_putchar('\n');
	ft_putnbr(strncmp("Hello", "Heloo", 3));
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putnbr(ft_strncmp("Hello","Heloo", 4));
	ft_putchar('\n');
	ft_putnbr(strncmp("Hello", "Heloo", 4));
	ft_putchar('\n');
	ft_putchar('\n');

	ft_putstr(ft_strcat(dest, "Je "));
	ft_putchar('\n');
	ft_putstr(ft_strcat(dest, "suis "));
	ft_putchar('\n');
	ft_putstr(ft_strcat(dest, "force "));
	ft_putchar('\n');
	ft_putstr(ft_strcat(dest, "d'admettre "));
	ft_putchar('\n');
	ft_putstr(ft_strcat(dest, "que ta fonction "));
	ft_putchar('\n');
	ft_putstr(ft_strcat(dest, "fonctionne bel et bien."));
	ft_putchar('\n');

	*dest = '\0';
	ft_putstr(ft_strncat(dest, "Je dsadsadas", 3));
	ft_putchar('\n');
	ft_putstr(ft_strncat(dest, "suis gfsdgsr", 5));
	ft_putchar('\n');
	ft_putstr(ft_strncat(dest, "force gresjfhfds", 6));
	ft_putchar('\n');
	ft_putstr(ft_strncat(dest, "d'admettre gfsaherahvr", 11));
	ft_putchar('\n');
	ft_putstr(ft_strncat(dest, "que ta fonction fdsagrefd", 16));
	ft_putchar('\n');
	ft_putstr(ft_strncat(dest, "fonctionne bel et bien.fesafewaEF", 23));

	ft_putchar('\n');
	ft_putchar('\n');

	if (ft_strstr("  dsanjkdnsa          ddnsaknls lol", " fdsafdsfdsaf  ") == NULL)
		ft_putstr("le pointeur est NULL");
	ft_putchar('\n');
	if (ft_strstr("  dsanjkdnsa          ddnsaknls lol", " fdsafdsfdsaf  ") == NULL)
		ft_putstr("le pointeur est NULL");
	ft_putchar('\n');
	ft_putchar('\n');

	ft_putstr(dest);
	ft_putchar('\n');
	ft_putnbr(ft_strlen(dest));
	ft_putchar('\n');
	ft_putstr("la taille de la chaine devrait faire : ");
	ft_putnbr(strlcat(dest, "012345678901234567890123456789012345isdndjsananjfnjdnjknadkaj", 99));
	ft_putchar('\n');
	ft_putstr("mais la taille reel est de : ");
	ft_putnbr(ft_strlen(dest));
	ft_putchar('\n');
	ft_putstr(dest);
	ft_putchar('\n');
	strcpy(dest, "Je suis force d'admettre que ta fonction fonctionne bel et bien.");
	ft_putchar('\n');
	ft_putnbr(ft_strlen(dest));
	ft_putchar('\n');
	ft_putstr("la taille de la chaine devrait faire : ");
	ft_putnbr(ft_strlcat(dest, "012345678901234567890123456789012345isdndjsananjfnjdnjknadkaj", 99));
	ft_putchar('\n');
	ft_putstr("mais la taille reel est de : ");
	ft_putnbr(ft_strlen(dest));
	ft_putchar('\n');
	ft_putstr(dest);
	ft_putchar('\n');
}

