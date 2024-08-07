/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 01:57:29 by judetre           #+#    #+#             */
/*   Updated: 2024/08/07 02:24:19 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int if_13_firt(char c)
{
	if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	char *str;
	str = argv[1];
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		while (*str)
		{
			if (uppercase(*str))
			{
				if (if_13_firt(*str))
					write(1 , (char[]){*str + 13}, 1);
				else
					write(1, (char[]){*str - 13}, 1);
			}
			else if (lowercase(*str))
			{
				if (if_13_firt(*str))
					write(1 , (char[]){*str + 13}, 1);
				else
					write(1, (char[]){*str - 13}, 1);
			}
			else
				write(1, str, 1);
			str++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
