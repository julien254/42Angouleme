/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 08:54:14 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/21 09:13:40 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_putstr(char *str)
{
        int     a;

        a = 0;
        while (str[a] != '\0')
        {
                ft_putchar(str[a]);
                a++;
        }
}

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
        int unsigned i;

        i = 0;
        while(src[i] != '\0' && i < n)
        {
                dest[i] = src[i];
                i++;
        }
	while(i < n)
	{
	      	dest[i] = '\0';
		i++;
	}
        return dest;
}

/*int main(void)
{
        char    dest[20];
        char    src[] = "lol c'est ouf !";

        ft_putstr(ft_strncpy(dest, src, 18));
}*/

