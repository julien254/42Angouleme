/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:31:02 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/20 08:20:51 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_find_lowest(int *lowest, int *temptab, int *index, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (temptab[j] <= *lowest)
		{
			*lowest = temptab[j];
			*index = j;
		}		
		j++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	temptab[10];
	int	i;
	int	index;
	int	lowest;	

	i = 0;
	while (i < size)
	{
		temptab[i] = tab[i];
		i++;
	}
	i = 0;
	lowest = temptab[0];
	while (i < size)
	{	
		ft_find_lowest(&lowest, temptab, &index, size);
		tab[i] = lowest;
		lowest = 2147483647;
		temptab[index] = 2147483647;
		i++;
	}
}
