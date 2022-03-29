/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:28:22 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/16 18:23:49 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_ligne(int x, char a, char b, char c)
{
	int	count1;

	count1 = 0;
	while (count1 <= x)
	{
		if (count1 == 0)
			ft_putchar(a);
		else if (count1 < x)
			ft_putchar(b);
		else
		{
			ft_putchar(c);
			ft_putchar('\n');
		}
		count1++;
	}
}

void	rush(int x, int y)
{
	int	count2;

	if (x <= 0 || y <= 0)
		return ;
	count2 = 0;
	while (count2 < y)
	{
		if (count2 == 0)
			ft_print_ligne(x, '/', '*', '\\');
		else if (count2 < y - 1)
			ft_print_ligne(x, '*', ' ', '*');
		else
			ft_print_ligne(x, '\\', '*', '/');
		count2++;
	}
}
