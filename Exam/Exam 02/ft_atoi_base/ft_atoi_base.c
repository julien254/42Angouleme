/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 05:06:32 by judetre           #+#    #+#             */
/*   Updated: 2024/08/07 05:44:18 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi_base(const char *str, int str_base)
{
	int isneg = 1;
	int i = 0;
	int result;

	if (str[i] == '-')
	{
		isneg = -isneg;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9' || str[i] >= 'A' && str[i] <= 'F' || str[i] >= 'a' && str[i] <= 'f' )
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * str_base + (str[i] - '0');
		if (str[i] >= 'A' && str[i] <= 'F')
			result = result * str_base + (str[i] - '7');
		if (str[i] >= 'a' && str[i] <= 'f')
			result = result * str_base + (str[i] - 'W');
		i++;
	}
	return (isneg * result);
}
