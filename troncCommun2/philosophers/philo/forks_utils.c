/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:16:18 by judetre           #+#    #+#             */
/*   Updated: 2024/08/19 12:19:06 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*take_left_first(t_thread_data *data)
{
	pthread_mutex_lock(data->forks_left);
	if (!if_philo_is_dead(data))
	{
		pthread_mutex_unlock(data->forks_left);
		return (NULL);
	}
	choose_print_routine(data, "fork_left");
	pthread_mutex_lock(data->forks_right);
	if (!if_philo_is_dead(data))
	{
		unlock_forks(data);
		return (NULL);
	}
	choose_print_routine(data, "fork_right");
	if (!if_philo_is_dead(data))
	{
		unlock_forks(data);
		return (NULL);
	}
	return ((void *)1);
}

void	*take_right_first(t_thread_data *data)
{
	pthread_mutex_lock(data->forks_right);
	if (!if_philo_is_dead(data))
	{
		pthread_mutex_unlock(data->forks_right);
		return (NULL);
	}
	choose_print_routine(data, "fork_right");
	pthread_mutex_lock(data->forks_left);
	if (!if_philo_is_dead(data))
	{
		unlock_forks(data);
		return (NULL);
	}
	choose_print_routine(data, "fork_left");
	if (!if_philo_is_dead(data))
	{
		unlock_forks(data);
		return (NULL);
	}
	return ((void *)1);
}

void	*choose_order_take_forks(t_thread_data *data)
{
	if (data->id % 2 == 0)
	{
		if (!take_left_first(data))
			return (NULL);
	}
	else
	{
		if (!take_right_first(data))
			return (NULL);
	}
	return ((void *)1);
}
