/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:31:02 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/20 10:57:01 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	temptab[];
	int	i;
	int	fin;

	i = 0;
	fin = size - 1;
	while (i < size)
	{
		temptab[i] = tab[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = temptab[fin];
		fin--;
		i++;
	}
}
