/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:46:16 by julien            #+#    #+#             */
/*   Updated: 2022/03/18 15:19:55 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_print_combn(int n)
{
	char	comb[12];

	ft_make_str(n, comb);
	ft_recurcive(comb, 0, n, -1);
}
