/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:14:45 by julien            #+#    #+#             */
/*   Updated: 2022/03/19 23:18:10 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	search_highest(int *tab, int *highest)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] > *highest)
		{
			*highest = tab[i];
		}
		i++;
	}
	return (i);
}

void	ft_sort_in_tab(int *tab, int size)
{
	int	index;
	int	i;
	int	lowest;
	int	highest;

	highest = search_highest(tab, &highest);
	index = 0;
	while (index < size)
	{
		i = index;
		lowest = highest;
		while (i < size)
		{
			if (tab[i] < lowest)
			{
				lowest = tab[i];
				ft_swap(tab + i, tab + index);
			}
			i++;
		}
		index++;
	}
}
