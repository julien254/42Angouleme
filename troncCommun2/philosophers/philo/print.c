/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:36:45 by judetre           #+#    #+#             */
/*   Updated: 2024/08/19 11:42:04 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print_err_argv(void)
{
	printf("Usage: ./philo [numbers of philosopher] [time to die] ");
	printf("[time to eat] [time to sleep] ");
	printf("[number_of_times_each_philosopher_must_eat](optional)\n");
}

void	choose_print_routine(t_thread_data *data, char *str)
{
	pthread_mutex_lock(data->mutex_print);
	pthread_mutex_lock(data->mutex_death);
	if (*data->philo_died == 0 || ft_strcmp(str, "died") == 0)
		print(data, str);
	pthread_mutex_unlock(data->mutex_death);
	pthread_mutex_unlock(data->mutex_print);
}

void	print(t_thread_data *data, char *str)
{
	unsigned long	current_time;

	current_time = get_current_time() - data->timestamp;
	if (ft_strcmp(str, "died") == 0)
		printf("%lu %d died\n", current_time, data->id + 1);
	else if (ft_strcmp(str, "eating") == 0)
		printf("%lu %d is eating\n", current_time, data->id + 1);
	else if (ft_strcmp(str, "fork_left") == 0)
		printf("%lu %d has take fork left\n", current_time, data->id + 1);
	else if (ft_strcmp(str, "fork_right") == 0)
		printf("%lu %d has take fork right\n", current_time, data->id + 1);
	else if (ft_strcmp(str, "sleeping") == 0)
		printf("%lu %d is sleeping\n", current_time, data->id + 1);
	else if (ft_strcmp(str, "thinking") == 0)
		printf("%lu %d is thinking\n", current_time, data->id + 1);
	else if (ft_strcmp(str, "debug") == 0)
		printf("debug\n");
}
