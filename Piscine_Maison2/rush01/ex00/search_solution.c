/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:00:02 by tomoron           #+#    #+#             */
/*   Updated: 2023/07/22 18:28:23 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//valeur de retour : nombre de solutions
#include <stdio.h>

int	ft_check_line(int *input, int *result, int index, int size);
int	ft_check_duplicates(int *array, int index, int array_size);

void ft_print_solution(int *a, int b)
{
	(void)a;
	(void)b;
	printf("solution trouve");
}

int	ft_search_solution(int *arr_input, int *res, int arr_s, int recurs_i)
{
	int	current_test;
	int	nb_printed;

	current_test = 1;
	nb_printed = 0;
	while (current_test <= arr_s)
	{
		res[recurs_i] = current_test;
		if (ft_check_duplicates(res, recurs_i, arr_s))
		{
			if ((recurs_i % arr_s) == (arr_s - 1) 
				&& !ft_check_line(arr_input, res, recurs_i - arr_s - 1, arr_s))
			{
				return (0);
			}
			if (recurs_i == (arr_s * arr_s) - 1)
			{
				ft_print_solution(res, arr_s);
				return (1);
			}
			nb_printed += ft_search_solution(arr_input, res, arr_s, \
				recurs_i + 1);
		}
		current_test++;
	}
	return (nb_printed);
}
