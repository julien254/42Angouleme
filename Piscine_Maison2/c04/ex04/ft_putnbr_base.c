/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 04:18:01 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/15 10:02:41 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_ptchar(char c)
{
	write(1, &c, 1);
}

int	f_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	base_error(char *base)
{
	int	i;

	if (f_strlen(base) < 2)
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

void	ft_putnbr_in_base(unsigned int nbr, unsigned int sizebase, char *base)
{
	if (nbr < sizebase)
		ft_ptchar(base[nbr]);
	else
	{
		ft_putnbr_in_base(nbr / sizebase, sizebase, base);
		ft_ptchar(base[nbr % sizebase]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;
	unsigned int	sizebase;

	if (base_error(base))
	{
		if (nbr < 0)
		{
			ft_ptchar('-');
			nb = nbr * -1;
		}
		else
			nb = nbr;
		sizebase = f_strlen(base);
		ft_putnbr_in_base(nb, sizebase, base);
	}
}
