/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:18:58 by mbobin            #+#    #+#             */
/*   Updated: 2022/02/01 12:37:41 by mbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "biblio.h"

//verifier aussi qu il y a une ligne avec au moins 1 carac
int	ft_len_ligne(char *str)
{
	(void)str;
	return (0);
}

int	ft_carac(char *str)
{
	(void)str;
	return (0);
}

int	ft_erreur_map(char *str)
{
	if (ft_len_ligne(str) == 1)
		return (1);
	
	if (ft_carac(str) == 1)
		return (1);
	return (0);
}

// coucou marc ,j'ai supprimer strlen qui est deja dans la boite a outils,
// jai void les argument des deux premiere fonction car ca complier pas sinn.
// derniere chose j'ai ajouter un return 0. 
