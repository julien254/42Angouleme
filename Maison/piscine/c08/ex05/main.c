/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:09:22 by julien            #+#    #+#             */
/*   Updated: 2022/03/25 10:59:53 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"

int	main(int argc, char *argv[])
{
	char *s1 = "je ";
	char *s2 = "suis ";
	char *s3 = "le ";
	char *s4 = "meilleur ";
	char *s5 = "loooooooool";
	char *s6 = "!!\n";
	char *tab1[6] = {s1, s2, s3, s4, s5, s6};
	t_stock_str *tab;

	(void)argc;
	(void)argv;
	tab = ft_strs_to_tab(6, tab1);
	ft_show_tab(tab);
	return (0);
}
