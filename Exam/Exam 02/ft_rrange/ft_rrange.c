/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:29:32 by judetre           #+#    #+#             */
/*   Updated: 2024/08/06 13:00:54 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int     *ft_rrange(int start, int end)
{
	int size;
	int *tab;
	int	i;



	if (start == end)
	{
		tab = (int *)malloc(sizeof(int) * 1);
		if (!tab)
			return (NULL);
		tab[0]= start;
	}
	else
	{
		size = start - end;
		if (size < 0)
			size = -size;
		size++;
		tab = (int *)malloc(sizeof(int) * size);
		if (end < start)
		{
			i = 0;
			while (i < size)
			{
				tab[i++] = end;
				end++;
			}
		}
		else
		{
			i = 0;
			while (i < size)
			{
				tab[i++] = end;
				end--;
			}
		}
	}
	return (tab);
}

/* int	main(int argc, char *argv[]) */
/* { */
/* 	(void)argc; */
/* 	int *tab; */
/* 	int i = 0; */
/* 	int size; */
/* 	tab = ft_rrange(atoi(argv[1]), atoi(argv[2])); */
/* 	size = atoi(argv[1]) - atoi(argv[2]); */
/* 	if (size < 0) */
/* 		size = -size; */
/* 	size++; */
/* 	while (i < size) */
/* 	{ */
/* 		printf("%d ", tab[i]); */
/* 		i++; */
/* 	} */

	/* return (0); */
/* } */
