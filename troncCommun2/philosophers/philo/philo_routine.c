/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:31:15 by judetre           #+#    #+#             */
/*   Updated: 2024/08/19 12:33:03 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	*if_err(t_thread_data *data)
{
	pthread_mutex_lock(data->mutex_print);
	if (*data->err == 1)
	{
		pthread_mutex_unlock(data->mutex_print);
		return (NULL);
	}
	pthread_mutex_unlock(data->mutex_print);
	return ((void *)1);
}

void	*philo_routine(void *arg)
{
	t_thread_data	*data;

	data = (t_thread_data *)arg;
	if (!if_err(data))
		return (NULL);
	thinking(data);
	while (1)
	{
		usleep(100);
		if (!if_err(data))
			return (NULL);
		if (data->id % 2 == 0)
			usleep(50);
		if (!eating(data))
			return (NULL);
		if (!sleeping(data))
			return (NULL);
		if (!thinking(data))
			return (NULL);
	}
}
