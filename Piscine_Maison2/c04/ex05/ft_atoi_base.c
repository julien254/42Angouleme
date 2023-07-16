/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:54:34 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/16 23:41:07 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_strlen_base(char *str, char *base)
{
	int	i;
	int	j;
	int	tcheck;

	i = 0;
	tcheck = 1;
	while (str[i] && tcheck)
	{
		j = 0;
		tcheck = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				tcheck = 1;
			j++;
		}
		if (tcheck == 1)
			i++;
	}
	return (i);
}

int	ft_power(int base, int puissance)
{
	int	result;

	result = 1;
	while (puissance)
	{
		result *= base;
		puissance--;
	}
	return (result);
}

int	base_error(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	if (i < 2)
		return (0);
	while (*base)
	{
		i = 1;
		while (base[i])
		{
			if (*base == base[i])
				return (0);
			i++;
		}
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (1);
}

unsigned int	ft_conv_char_base_in_int(char *str, char *base, int size_str)
{
	int				i;
	int				j;
	unsigned int	result;
	int				base_size;
	int				pos;

	i = 0;
	result = 0;
	while (base[i])
		i++;
	base_size = i;
	i = 0;
	while (i != size_str)
	{
	j = 0;
		while (str[i] != base[j])
			j++;
		pos = j;
		result += pos * ft_power(base_size, size_str - 1 - i);
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	unsigned int	result;
	int	str_size;

	if(base_error(base) == 0)
		return (0);
	i = 0;
	neg = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	str = &str[i];
	str_size = ft_strlen_base(str, base);
	if (str_size == 0)
		return (0);
	else
		result = ft_conv_char_base_in_int(str, base, str_size);
	return ((int)(result * neg));
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int	result;
	result = ft_atoi_base("        ---++70101000", "0123456789ABCDEF");
	printf("%d\n", result);
	return (0);
}


