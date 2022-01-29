/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:43:23 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/26 08:16:26 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
}

/*int main(void)
{
	char str[] = "crasher c'est mal!";
	char str1[] = "faut pas respirer la compote, ca fait tousser !!!";
	char str2[] = "COUillere!!!";
	char str3[] = "Morduuuuu !!!";

	ft_strupcase(str);
	ft_strupcase(str1);
	ft_strupcase(str2);
	ft_strupcase(str3);
	printf("%s", str);
	printf("%s", str1);
	printf("%s", str2);
	printf("%s", str3);
}*/
