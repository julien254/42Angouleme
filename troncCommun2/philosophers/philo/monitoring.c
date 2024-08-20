/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:51:49 by judetre           #+#    #+#             */
/*   Updated: 2024/08/19 11:53:47 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	check_eating_count(t_threads *philo, int *count, int i)
{
	pthread_mutex_lock(philo->data[i].mutex_eating_count);
	if (philo->data[i].eating_count == philo->eating_count && \
			philo->eating_count != 0 && \
			philo->data[i].ate_everything != 1)
	{
		*count = *count + 1;
		philo->data[i].ate_everything = 1;
	}
	pthread_mutex_unlock(philo->data[i].mutex_eating_count);
}

void	monitoring(t_threads *philo)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (1)
	{
		usleep(100);
		check_eating_count(philo, &count, i);
		pthread_mutex_lock(&philo->mutex_last_eat[i]);
		if (get_current_time() - philo->data[i].last_eat_time >= \
			(unsigned long)philo->time_to_die || count == philo->number_philo)
		{
			pthread_mutex_unlock(&philo->mutex_last_eat[i]);
			pthread_mutex_lock(&philo->mutex_death);
			philo->philo_died = 1;
			pthread_mutex_unlock(&philo->mutex_death);
			if (count != philo->number_philo)
				choose_print_routine(&philo->data[i], "died");
			break ;
		}
		pthread_mutex_unlock(&philo->mutex_last_eat[i++]);
		if (i == philo->number_philo)
			i = 0;
	}
}
