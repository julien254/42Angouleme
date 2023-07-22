/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ligne.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:28:19 by judetre           #+#    #+#             */
/*   Updated: 2023/07/22 17:43:51 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_check_line_to_right(int row_left_value, int *result, int index, int size)
{
	int	i;
	int	count;

	i = 1;
	count = 1;
	while (i < size)
	{
		if (result[index] < result[index + 1])
		{
			count++;
			index++;
		}
		i++;
	}
	if (count == row_left_value)
		return (1);
	printf("erreur check to right\n");
	return (0);
}

int	ft_check_line_to_left(int row_right_value, int *result, int index, int size)
{
	int	i;
	int	count;

	i = 1;
	count = 1;
	index += size - 1;
	while (i < size)
	{
		if (result[index] < result[index - 1])
		{
			count++;
			index--;
		}
		i++;
	}
	if (count == row_right_value)
		return (1);
	printf("erreur check to left\n");
	return (0);
}
int	ft_check_line(int *input, int *result, int index, int size)
{
	int	row_left_value;
	int	row_right_value;
	int	line;

	line = index / size;
	row_left_value = input[size * 2 + line];
	row_right_value = input[size * 2 + line + size];
	printf("%d\n%d\n%d\n", line, row_left_value, row_right_value);
	if (ft_check_line_to_right(row_left_value, result, index, size) && ft_check_line_to_left(row_right_value, result, index, size))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int input[16] = {4,3,2,1,1,2,2,2,4,3,2,1,1,2,2,2};
	int result[16] = {1,2,4,3,0,0,0,0,0,0,0,0,0,0,0,0};


	printf("%d" ,ft_check_line(input, result, 0, 4));
	return (0);
}
