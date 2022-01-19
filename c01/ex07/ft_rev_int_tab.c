/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:31:02 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/17 14:09:37 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int temptab[size];
	int i;
	int fin;
	
	
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
