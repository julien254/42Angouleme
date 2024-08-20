/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:30:27 by judetre           #+#    #+#             */
/*   Updated: 2024/08/19 12:34:38 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	init_philo_data(t_threads *philo)
{
	int	err;

	err = init_mutex(philo, philo->number_philo);
	if (err)
		return (1);
	philo->data = init_data(philo);
	if (!philo->data)
		return (1);
	philo->threads = malloc_threads(philo->number_philo);
	if (!philo->threads)
		return (1);
	err = init_threads(philo);
	if (err)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_threads		philo;
	int				err;

	if (argc != 5 && argc != 6)
		print_err_argv();
	else
	{
		if (!set_argv(&philo, argv, argc))
		{
			printf("Error argv\n");
			return (1);
		}
		err = init_philo_data(&philo);
		if (!err)
			monitoring(&philo);
		else
		{
			pthread_mutex_lock(&philo.mutex_print);
			philo.err = 1;
			printf("Error init\n");
			pthread_mutex_unlock(&philo.mutex_print);
		}
		free_all(&philo);
	}
	return (0);
}
