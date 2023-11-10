/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:34:16 by jdetre            #+#    #+#             */
/*   Updated: 2023/11/07 15:20:44 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(int argc, char *argv[])
{

	(void)argc;
	(void)argv;
	ft_printf("ab%5%lool%");

	/* printf("%d", printf(" %llx ", 9223372036854775807LL)); */
	/* printf("%d", ft_printf(" %x ", 9223372036854775807LL)); */
	/* printf("\n"); */
	/* printf("%d", printf(" %lx ", LONG_MAX)); */
	/* printf("%d", ft_printf(" %x ", LONG_MAX)); */
	/* printf("\n"); */
	/* printf("%d", printf(" %lx ", LONG_MIN)); */
	/* printf("%d", ft_printf(" %x ", LONG_MIN)); */
	/* printf("\n"); */
	/* printf("%d", printf(" %lx ", ULONG_MAX)); */
	/* printf("%d", ft_printf(" %x ", ULONG_MAX)); */
	/* printf("\n"); */
	return (0);
}
