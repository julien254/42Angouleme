/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:16:21 by judetre           #+#    #+#             */
/*   Updated: 2024/08/07 16:32:20 by judetre          ###   ########.fr       */
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
		int i;

		i = 0;
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			write(1, &str[i], 1);
			i++;
		}
		while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				write(1, "_", 1);
				write(1, (char[]){str[i] + ' '}, 1);
			}
			else
				write(1, &str[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
