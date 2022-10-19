/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:23:09 by julien            #+#    #+#             */
/*   Updated: 2022/10/13 20:12:07 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_all_letsgo(t_lst_img *boximg)
{
	if (boximg->letsgo_down == 0 || \
			boximg->letsgo_up == 0)
		return (0);
	return (1);
}
