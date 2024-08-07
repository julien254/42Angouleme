/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:09:11 by judetre           #+#    #+#             */
/*   Updated: 2024/08/07 16:14:14 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int	main(int argc, char *argv[])
{
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		char *str = argv[1];
		while (*str)
			str++;
		str--;
		while (str != argv[1] - 1)
		{
			write(1, str--, 1);
		}
		write(1, "\n", 1);
	}
	return (0);
}
