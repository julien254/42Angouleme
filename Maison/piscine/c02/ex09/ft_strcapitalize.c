/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:43:23 by jdetre            #+#    #+#             */
/*   Updated: 2022/03/19 23:13:35 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[0] >= 'a' && str[i] <= 'z')
	{
		str[0] = str[0] - 32;
	}
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && (!(str[i - 1] >= 'a' \
				&& str[i - 1] <= 'z')) && (!(str[i - 1] >= 'A' \
				&& str[i - 1] <= 'Z')) && (!(str[i - 1] >= '0' \
				&& str[i - 1] <= '9')))
			str[i] = str[i] - 32;
		else if ((str[i] >= 'A' && str[i] <= 'Z') && ((str[i - 1] >= 'a' \
				&& str[i - 1] <= 'z') || (str[i - 1] >= 'A' && \
				str[i - 1] <= 'Z') || (str[i - 1] >= '0' \
				&& str[i - 1] <= '9')))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
/*int	main(void)
{
	char str[] = "nNnnNNnnNN 87889nNnnNNnnN!";
	char str1[] = "faut pas 556Respirer la compote, ca fait tousser !!!";
	char str2[] = "COUillere!!!";
	char str3[] = "morduuuuu !!!";

	ft_strcapitalize(str);
	ft_strcapitalize(str1);
	ft_strcapitalize(str2);
	ft_strcapitalize(str3);
	printf("%s", str);
	printf("%s", str1);
	printf("%s", str2);
	printf("%s", str3);
}*/
