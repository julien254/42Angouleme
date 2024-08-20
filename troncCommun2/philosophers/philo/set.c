/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:20:51 by judetre           #+#    #+#             */
/*   Updated: 2024/08/19 12:22:29 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	set_data(t_threads *philo, t_thread_data *data)
{
	int	i;

	i = 0;
	while (i < philo->number_philo)
	{
		data[i].id = i;
		data[i].number_philo = philo->number_philo;
		data[i].time_to_eat = philo->time_to_eat;
		data[i].time_to_sleep = philo->time_to_sleep;
		data[i].forks_left = &philo->forks[i];
		data[i].forks_right = &philo->forks[(i + 1) % data[0].number_philo];
		data[i].mutex_print = &philo->mutex_print;
		data[i].mutex_death = &philo->mutex_death;
		data[i].mutex_last_eat = &philo->mutex_last_eat[i];
		data[i].mutex_eating_count = &philo->mutex_eating_count[i];
		data[i].philo_died = &philo->philo_died;
		data[i].eating_count = 0;
		data[i].ate_everything = 0;
		data[i].err = &philo->err;
		i++;
	}
}

void	*set_argv(t_threads *philo, char **argv, int argc)
{
	ft_memset(philo, 0, sizeof(t_threads));
	if (argc == 5)
		philo->eating_count = 0;
	else
		philo->eating_count = ft_atoi(argv[5]);
	if (argc == 6 && philo->eating_count <= 0)
		return (NULL);
	philo->number_philo = ft_atoi(argv[1]);
	if (philo->number_philo <= 0)
		return (NULL);
	philo->time_to_die = ft_atoi(argv[2]);
	if (philo->time_to_die <= 0)
		return (NULL);
	philo->time_to_eat = ft_atoi(argv[3]);
	if (philo->time_to_eat <= 0)
		return (NULL);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (philo->time_to_sleep <= 0)
		return (NULL);
	return ((void *)1);
}
