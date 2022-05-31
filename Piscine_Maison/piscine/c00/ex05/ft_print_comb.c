/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:46:16 by julien            #+#    #+#             */
/*   Updated: 2022/03/13 16:13:08 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_make_str(int n, char *comb)
{
	int		i;

	i = 0;
	while (i < n)
	{
		comb[i] = '0';
		i++;
	}
	comb[n] = ',';
	comb[n + 1] = ' ';
	comb[n + 2] = '\0';
}

void	ft_recurcive(char *comb, int niveau, int n, int courant_num)
{
	int	next_num;

	if (niveau == n)
	{
		if (comb[n - 1] == '9' && comb[0] == '0' + 10 - n)
			write(1, comb, n);
		else
			write(1, comb, n + 2);
	}
	else
	{
		next_num = courant_num + 1;
		while (next_num != 11 - (n - niveau))
		{
		comb[niveau] = '0' + next_num;
			ft_recurcive(comb, niveau + 1, n, next_num);
			next_num++;
		}
	}
}

void	ft_print_comb(void)
{
	char	comb[12];

	ft_make_str(3, comb);
	ft_recurcive(comb, 0, 3, -1);
}
