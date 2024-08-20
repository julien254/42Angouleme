/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:13:01 by judetre           #+#    #+#             */
/*   Updated: 2024/08/19 12:15:21 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	free_malloc(t_threads *philo)
{
	if (philo->data)
		free(philo->data);
	if (philo->forks)
		free(philo->forks);
	if (philo->mutex_last_eat)
		free(philo->mutex_last_eat);
	if (philo->mutex_eating_count)
		free(philo->mutex_eating_count);
	if (philo->threads)
		free(philo->threads);
}

void	free_all(t_threads *philo)
{
	int	i;

	i = 0;
	while (i < philo->count_threads)
		pthread_join(philo->threads[i++], NULL);
	i = 0;
	while (i < philo->count_mutex[0])
		pthread_mutex_destroy(&philo->forks[i++]);
	i = 0;
	while (i < philo->count_mutex[1])
		pthread_mutex_destroy(&philo->mutex_last_eat[i++]);
	i = 0;
	while (i < philo->count_mutex[2])
		pthread_mutex_destroy(&philo->mutex_eating_count[i++]);
	if (philo->count_mutex[3])
		pthread_mutex_destroy(&philo->mutex_print);
	if (philo->count_mutex[4])
		pthread_mutex_destroy(&philo->mutex_death);
	free_malloc(philo);
}
