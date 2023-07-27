/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:05:40 by judetre           #+#    #+#             */
/*   Updated: 2023/07/27 17:27:58 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);
int	base_error(char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* void	ft_putnbr_in_base(unsigned int nbr, unsigned int sizebase, char *base) */
/* { */
/* 	if (nbr < sizebase) */
/* 		ft_ptchar(base[nbr]); */
/* 	else */
/* 	{ */
/* 		ft_putnbr_in_base(nbr / sizebase, sizebase, base); */
/* 		ft_ptchar(base[nbr % sizebase]); */
/* 	} */
/* } */

/* void	ft_putnbr_base(int nbr, char *base) */
/* { */
/* 	unsigned int	nb; */
/* 	unsigned int	sizebase; */

	/* if (base_error(base)) */
	/* { */
	/* 	if (nbr < 0) */
	/* 	{ */
	/* 		ft_ptchar('-'); */
	/* 		nb = nbr * -1; */
	/* 	} */
	/* 	else */
	/* 		nb = nbr; */
	/* 	sizebase = ft_strlen(base); */
	/* 	ft_putnbr_in_base(nb, sizebase, base); */
	/* } */
/* } */

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		ten_base;
	int		ten_base_temp;
	int		i;
	int		sizebase;

	sizebase = ft_strlen(base_from);
	i = 0;
	ten_base = ft_atoi_base(nbr, base_from);
	printf("%d\n", ten_base);
	ten_base_temp = ten_base;
	while (ten_base_temp >= sizebase)
	{
		ten_base_temp /= sizebase;
		printf("%d\n", ten_base_temp);
		i++;
	}
	result = (char *)malloc(sizeof(char) * i + 2);
	printf("%d\n", i);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_convert_base("7f", "0123456789abcdef", "01");
	return (0);
}
