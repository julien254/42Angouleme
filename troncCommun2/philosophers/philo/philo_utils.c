/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:23:39 by judetre           #+#    #+#             */
/*   Updated: 2024/08/19 12:30:02 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

unsigned long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	*if_philo_is_dead(t_thread_data *data)
{
	pthread_mutex_lock(data->mutex_death);
	if (*data->philo_died)
	{
		pthread_mutex_unlock(data->mutex_death);
		return (NULL);
	}
	pthread_mutex_unlock(data->mutex_death);
	return ((void *)1);
}

int	if_philo_is_solo(t_thread_data *data)
{
	if (data->number_philo == 1)
	{
		choose_print_routine(data, "fork_left");
		return (1);
	}
	return (0);
}

void	unlock_forks(t_thread_data *data)
{
	pthread_mutex_unlock(data->forks_left);
	pthread_mutex_unlock(data->forks_right);
}
