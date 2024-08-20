/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:56:21 by judetre           #+#    #+#             */
/*   Updated: 2024/08/19 12:12:14 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	init_tab_mutex(t_threads *philo)
{
	int	i;
	int	err;

	i = 0;
	while (i < philo->number_philo)
	{
		err = pthread_mutex_init(&philo->forks[i], NULL);
		if (err)
			return (1);
		philo->count_mutex[0]++;
		err = pthread_mutex_init(&philo->mutex_last_eat[i], NULL);
		if (err)
			return (1);
		philo->count_mutex[1]++;
		err = pthread_mutex_init(&philo->mutex_eating_count[i], NULL);
		if (err)
			return (1);
		philo->count_mutex[2]++;
		i++;
	}
	return (0);
}

int	init_mutex(t_threads *philo, int number_of_philo)
{
	int	err;

	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* number_of_philo);
	philo->mutex_last_eat = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* number_of_philo);
	philo->mutex_eating_count = (pthread_mutex_t *)malloc(\
			sizeof(pthread_mutex_t) * number_of_philo);
	if (!philo->forks || !philo->mutex_last_eat || !philo->mutex_eating_count)
		return (1);
	err = init_tab_mutex(philo);
	if (err)
		return (1);
	err = pthread_mutex_init(&philo->mutex_print, NULL);
	if (err)
		return (1);
	philo->count_mutex[3]++;
	err = pthread_mutex_init(&philo->mutex_death, NULL);
	if (err)
		return (1);
	philo->count_mutex[4]++;
	return (0);
}

t_thread_data	*init_data(t_threads *philo)
{
	t_thread_data	*data;

	data = (t_thread_data *)malloc(sizeof(t_thread_data) * philo->number_philo);
	if (!data)
		return (NULL);
	set_data(philo, data);
	return (data);
}

pthread_t	*malloc_threads(int number_of_philo)
{
	pthread_t	*threads;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * number_of_philo);
	if (!threads)
		return (NULL);
	return (threads);
}

int	init_threads(t_threads *philo)
{
	int	i;
	int	err;

	i = 0;
	philo->timestamp = get_current_time();
	while (i < philo->data[0].number_philo)
	{
		philo->data[i].timestamp = philo->timestamp;
		philo->data[i].last_eat_time = get_current_time();
		err = pthread_create(&philo->threads[i], NULL, philo_routine, \
				&philo->data[i]);
		if (err)
			return (1);
		philo->count_threads++;
		i++;
	}
	return (0);
}
