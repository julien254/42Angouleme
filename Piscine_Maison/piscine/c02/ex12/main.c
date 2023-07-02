/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:57:59 by julien            #+#    #+#             */
/*   Updated: 2022/03/23 14:58:00 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_print_memory.c"
int	main(int argc, char *argv[])
{
	char	*str;

	(void)argc;
	(void)argv;
	str = "jecomprend pas loooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo";
	ft_print_memory(str, 92);
	return (0);
}
