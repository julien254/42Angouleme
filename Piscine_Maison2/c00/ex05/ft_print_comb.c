/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:43:18 by judetre           #+#    #+#             */
/*   Updated: 2023/07/11 11:08:08 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	make_comb(char *comb, int ncomb)
{
	int	i;

	i = 0;
	while (i < ncomb)
	{
		comb[i] = '0';
		i++;
	}
	comb[i] = ',';
	comb[i + 1] = ' ';
	comb[i + 2] = '\0';
}

void	ft_recurcive(char *comb, int ncomb, int niveau, int courant_num)
{
	int	next_num;

	if (niveau == ncomb)
	{
		if (comb[niveau - 1] == '9' && comb[0] == '0' + 10 - ncomb)
			write(1, comb, ncomb);
		else
			write(1, comb, ncomb + 2);
	}
	else
	{
		next_num = courant_num + 1;
		while (next_num <= 10 - (ncomb - niveau))
		{
			comb[niveau] = '0' + next_num;
			ft_recurcive(comb, ncomb, niveau + 1, next_num);
			next_num++;
		}
	}
}

void	ft_print_comb(void)
{
	char	comb[13];

	make_comb(comb, 3);
	ft_recurcive(comb, 3, 0, -1);
}
