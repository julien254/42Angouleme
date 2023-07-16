/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:15:53 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/11 21:51:38 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size)
	{
		j = i;
		min = tab[j];
		while (j < size)
		{
			if (tab[j] < min)
			{
				min = tab[j];
				swap(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}
