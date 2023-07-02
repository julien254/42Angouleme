/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:09:58 by jdetre            #+#    #+#             */
/*   Updated: 2023/06/20 12:53:01 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_sw(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ft_sw(&tab[i], &tab[size - 1 - i]);
		i++;
	}
}
