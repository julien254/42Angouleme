/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:43:27 by judetre           #+#    #+#             */
/*   Updated: 2024/08/19 11:50:21 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*wait(int time_wait, t_thread_data *data)
{
	unsigned long	current_time;
	unsigned long	time_of_end;

	current_time = get_current_time();
	time_of_end = current_time + time_wait;
	while (get_current_time() < time_of_end)
	{
		usleep(50);
		if (!if_philo_is_dead(data))
			return (NULL);
	}
	return ((void *)1);
}

void	*thinking(t_thread_data *data)
{
	if (!if_philo_is_dead(data))
		return (NULL);
	choose_print_routine(data, "thinking");
	return ((void *)1);
}

void	*eating(t_thread_data *data)
{
	void	*statut;

	if (if_philo_is_solo(data))
		return (NULL);
	if (!if_philo_is_dead(data))
		return (NULL);
	if (!choose_order_take_forks(data))
		return (NULL);
	choose_print_routine(data, "eating");
	pthread_mutex_lock(data->mutex_last_eat);
	data->last_eat_time = get_current_time();
	pthread_mutex_unlock(data->mutex_last_eat);
	statut = wait(data->time_to_eat, data);
	if (!statut)
	{
		unlock_forks(data);
		return (NULL);
	}
	pthread_mutex_lock(data->mutex_eating_count);
	data->eating_count++;
	pthread_mutex_unlock(data->mutex_eating_count);
	unlock_forks(data);
	return ((void *)1);
}

void	*sleeping(t_thread_data *data)
{
	void	*statut;

	if (!if_philo_is_dead(data))
		return (NULL);
	choose_print_routine(data, "sleeping");
	statut = wait(data->time_to_sleep, data);
	if (!statut)
		return (NULL);
	return ((void *)1);
}
