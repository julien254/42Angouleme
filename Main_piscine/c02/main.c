/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:00:18 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/02 13:20:41 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main test for c02 */
#include "../piscine.h"
#include <string.h>
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char dest[30];
	char str[] = "je suis Le grand magicien Ton pere.\n";
	char str2[] = "saLut, coMment tu vAs ? 42Mots quarante-Deux; ciNquante+eT+un";

	ft_strcpy(dest, "lol je suis trop con.");
	printf("%s\n", dest);
	strcpy(dest, "lol je suis trop beau.");
	printf("%s\n", dest);

	ft_putchar('\n');
	ft_putchar('\n');

	ft_strncpy(dest, "hummm les donuts :P.", 20);
	ft_putstr(dest);
	ft_putchar('\n');
	ft_strncpy(dest, "hummm les donuts :P.", 21);
	ft_putstr(dest);
	ft_putchar('\n');
	ft_strncpy(dest, "hummm les donuts :P.", 30);
	ft_putstr(dest);

	ft_putchar('\n');
	ft_putchar('\n');

	printf("%d\n", ft_str_is_alpha("ABCDEFGHIJKLMNOPQRSTUVWXabcdefghijklmnopqrstuvw"));
	printf("%d\n", ft_str_is_alpha("AKFDLDJKSAJgsfsfdIFINAdsadwdSSJID"));
	printf("%d\n", ft_str_is_alpha(""));
	printf("%d\n", ft_str_is_alpha("AKFDLDJKSA2JgsfsfdIFINAdsadwdSSJID"));
	printf("%d\n", ft_str_is_alpha("AKFDLDJK,SAJgsfsfdIFINAdsadwdSSJID"));

	ft_putchar('\n');
	ft_putchar('\n');

	printf("%d\n", ft_str_is_numeric("0123456789"));
	printf("%d\n", ft_str_is_numeric("17812378562986553492856923894723"));
	printf("%d\n", ft_str_is_numeric(""));
	printf("%d\n", ft_str_is_numeric("2374837439280j3,28473208942"));
	printf("%d\n", ft_str_is_numeric("AKFDLDJKSAJgsfsfdIFINAdsadwdSSJID,"));

	ft_putchar('\n');
	ft_putchar('\n');

	printf("%d\n", ft_str_is_lowercase("abcdefghijklmnopqrstuvwxyz"));
	printf("%d\n", ft_str_is_lowercase("rhhugiternkjrheiugrhekjsbfeuyhgjkrebfhufajrbiulghfad"));
	printf("%d\n", ft_str_is_lowercase(""));
	printf("%d\n", ft_str_is_lowercase("fdsufhauD"));
	printf("%d\n", ft_str_is_lowercase("AKFDLDJKSAJgsfsfdIFINAdsadwdSSJID,"));

	ft_putchar('\n');
	ft_putchar('\n');

	printf("%d\n", ft_str_is_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	printf("%d\n", ft_str_is_uppercase("FDNSKJFNEJKSFENWFNJDSKNFESKJLHNLDSBFLESNGJLZDHFJSD"));
	printf("%d\n", ft_str_is_uppercase(""));
	printf("%d\n", ft_str_is_uppercase("ABCDEFGHI JKLMNOPQRSTUVWXYZ"));
	printf("%d\n", ft_str_is_uppercase("ABCDEFGHIJK,LMNOPQRSTUVWXYZ"));

	ft_putchar('\n');
	ft_putchar('\n');

	printf("%d\n", ft_str_is_printable("ABCDEFGHIJKLMNOPQRSTUVWXYZ dsajdksajl"));
	ft_putstr("ABCDEFGHIJKLMNOPQRSTUVWXYZ dsajdksajl\n");
	printf("%d\n", ft_str_is_printable("ABCDEFGHIJKLMN , ; )3221OPQRSTUVWXYZ"));
	ft_putstr("ABCDEFGHIJKLMN , ; )3221OPQRSTUVWXYZ\n");
	printf("%d\n", ft_str_is_printable("abc\177"));
	ft_putstr("abc\177\n");
	printf("%d\n", ft_str_is_printable("ABCDEFGHIJKLMNOPQRS\2TUVWXYZ"));
	ft_putstr("ABCDEFGHIJKLMNOPQRS\2TUVWXYZ\n");

	ft_putchar('\n');
	ft_putchar('\n');

	ft_putstr(ft_strupcase(str));
	ft_putstr(ft_strlowcase(str));

	ft_putchar('\n');
	ft_putchar('\n');

	ft_putstr(ft_strcapitalize(str2));

	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr("------------------------->");

	ft_putstr(dest);
	ft_putchar('\n');
	ft_putnbr(strlcpy(dest, "lol", 3));
	ft_putchar('\n');
	ft_putstr(dest);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putnbr(strlcpy(dest, "lol", 4));
	ft_putstr(dest);
	ft_putchar('\n');
	ft_putstr("------------------------->");

	ft_putchar('\n');
	ft_putchar('\n');

	ft_putstr_non_printable(" les caracteres imprimable sont :\1 \2 \3 \4 \5 \6 \7 \10 \11 \12 \13 \14 \15 \16 \17 \20 \21 \22 \23 \24 \25 \26 \27 \30 \31 \32 \33 \34 \35 \36 \37. Et n'oublions pas le caractere 127 qui est :\177");

	ft_putchar('\n');
	ft_putchar('\n');

	ft_print_memory("Bonjour les aminches\11\12\11c  est fou\11tout\11ce qu on peut faire avec\11\12\11print_memory\12\12\12\11lol.lol\12 \0", 92);

}
