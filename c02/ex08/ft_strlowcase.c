/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:43:23 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/26 08:21:56 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

/*int main(void)
{
	char str[] = "NNnnNNnnNN 87889 NNnnNNnnN!";
	char str1[] = "faut pas respirer la compote, ca fait tousser !!!";
	char str2[] = "COUillere!!!";
	char str3[] = "Morduuuuu !!!";

	ft_strlowcase(str);
	ft_strlowcase(str1);
	ft_strlowcase(str2);
	ft_strlowcase(str3);
	printf("%s", str);
	printf("%s", str1);
	printf("%s", str2);
	printf("%s", str3);
}*/
