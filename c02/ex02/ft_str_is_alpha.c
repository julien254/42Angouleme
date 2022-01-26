/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:43:23 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/21 10:37:44 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z') || \
			(str[i] >= 'a'  && str[i] <= 'z')))
			return (0);
		i++;
	}
	return (1);
}

/*int main(void)
{
	char *str;
	char *str1;
	char *str2;
	char *str3;

	str = "sAlut";
	str1 = "sAlut ";
	str2 = "salut";
	str3 = "sA;lut";
	printf("%d", ft_str_is_alpha(str));
	printf("%d", ft_str_is_alpha(str1));
	printf("%d", ft_str_is_alpha(str2));
	printf("%d", ft_str_is_alpha(str3));
}*/
