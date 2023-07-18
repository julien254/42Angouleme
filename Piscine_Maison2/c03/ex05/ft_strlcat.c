/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:29:39 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/17 10:01:35 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] && i < size)
		i++;
	j = 0;
	if (i < size)
	{
		while (src[j] && i < size - 1)
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	while (src[j])
	{
		j++;
		i++;
	}
	return (i);
}
