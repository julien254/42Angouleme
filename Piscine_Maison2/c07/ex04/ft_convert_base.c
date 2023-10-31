/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:05:40 by judetre           #+#    #+#             */
/*   Updated: 2023/07/31 17:20:31 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

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

void	ft_setnbr_in_base(unsigned int nbr, char *base, int i, char *result)
{
	if (nbr < (unsigned int)ft_strlen(base))
	{
		result[i] = base[nbr];
		i--;
	}
	else
	{
		result[i] = base[nbr % ft_strlen(base)];
		ft_setnbr_in_base(nbr / ft_strlen(base), base, i - 1, result);
	}
}

char	*ft_setnbr_base(char *result, int nbr, char *base, int len_nbr)
{
	unsigned int	nb;
	int				i;

	i = 0;
	if (base_error(base))
	{
		if (nbr < 0)
		{
			result[i] = '-';
			nb = nbr * -1;
			i++;
		}
		else
			nb = nbr;
		i += len_nbr - 1;
		ft_setnbr_in_base(nb, base, i, result);
	}
	else
		return (NULL);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		ten_base;
	int		ten_base_temp;
	int		len_nbr;

	if (nbr == NULL || base_from == NULL || base_to == NULL)
		return (NULL);
	if (base_error(base_from) == 0)
		return (NULL);
	len_nbr = 1;
	ten_base = ft_atoi_base(nbr, base_from);
	ten_base_temp = ten_base;
	if (ten_base_temp < 0)
		ten_base_temp *= -1;
	while (ten_base_temp >= ft_strlen(base_to))
	{
		ten_base_temp /= ft_strlen(base_to);
		len_nbr++;
	}
	result = (char *)malloc(sizeof(char) * len_nbr + 2);
	result = ft_setnbr_base(result, ten_base, base_to, len_nbr);
	if (result == NULL)
		return (NULL);
	return (result);
}
