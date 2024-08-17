/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:30:27 by judetre           #+#    #+#             */
/*   Updated: 2024/08/17 16:23:07 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(char *str)
{
	size_t	i;
	long	nbr;

	i = 0;
	if (!ft_isdigit(str))
		return(-1);
	if (ft_strlen(str) >= 12 || (ft_strlen(str) == 11 && str[0] != '+'))
		return (-1);
	if (str[i] == '+')
		i++;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (nbr > 2147483647)
		return (-1);
	return (nbr);
}

unsigned long get_current_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));

}

void	print(t_thread_data *data, char *str)
{
	if (ft_strcmp(str, "died") == 0)
		printf("%lu %d died\n", get_current_time() - data->timestamp, data->id + 1);
	else if (ft_strcmp(str, "eating") == 0)
		printf("%lu %d is eating\n", get_current_time() - data->timestamp, data->id + 1);
	else if (ft_strcmp(str, "fork_left") == 0)
		printf("%lu %d has take fork left\n", get_current_time() - data->timestamp, data->id + 1);
	else if (ft_strcmp(str, "fork_right") == 0)
		printf("%lu %d has take fork right\n", get_current_time() - data->timestamp, data->id + 1);
	else if (ft_strcmp(str, "sleeping") == 0)
		printf("%lu %d is sleeping\n", get_current_time() - data->timestamp, data->id + 1);
	else if (ft_strcmp(str, "thinking") == 0)
		printf("%lu %d is thinking\n", get_current_time() - data->timestamp, data->id + 1);
	else if (ft_strcmp(str, "debug") == 0)
		printf("debug\n");
}
/* Option is an option if the param of nbr of eat by philo is set*/
void	choose_print_routine(t_thread_data *data, char *str)
{
	pthread_mutex_lock(data->mutex_print);
	print(data, str);
	pthread_mutex_unlock(data->mutex_print);	
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

void	*wait(int time_wait, t_thread_data *data)
{
	unsigned long 	current_time;
	unsigned long 	time_of_end;

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

void	*sleeping(t_thread_data *data)
{
	void *statut;

	if (!if_philo_is_dead(data))
		return (NULL);
	choose_print_routine(data, "sleeping");
	statut = wait(data->time_to_sleep, data);
	if (!statut)
		return (NULL);
	return ((void *)1);
}

void	*eating(t_thread_data *data)
{
	void *statut;

	if (!if_philo_is_dead(data))
		return (NULL);
	if (data->id % 2 == 0)
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
			pthread_mutex_unlock(data->forks_left);
			pthread_mutex_unlock(data->forks_right);
			return (NULL);
		}
		choose_print_routine(data, "fork_right");
		if (!if_philo_is_dead(data))
		{
			pthread_mutex_unlock(data->forks_left);
			pthread_mutex_unlock(data->forks_right);
			return (NULL);
		}
	}
	else
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
			pthread_mutex_unlock(data->forks_right);
			pthread_mutex_unlock(data->forks_left);
			return (NULL);
		}
		choose_print_routine(data, "fork_left");
		if (!if_philo_is_dead(data))
		{
			pthread_mutex_unlock(data->forks_right);
			pthread_mutex_unlock(data->forks_left);
			return (NULL);
		}
	}
	choose_print_routine(data, "eating");
	pthread_mutex_lock(data->mutex_last_eat);
	data->last_eat_time = get_current_time();
	pthread_mutex_unlock(data->mutex_last_eat);
	statut = wait(data->time_to_eat, data);
	if (!statut)
	{
		pthread_mutex_unlock(data->forks_left);
		pthread_mutex_unlock(data->forks_right);
		return (NULL);
	}
	pthread_mutex_lock(data->mutex_eating_count);
	data->eating_count++;
	pthread_mutex_unlock(data->mutex_eating_count);
	pthread_mutex_unlock(data->forks_left);
	pthread_mutex_unlock(data->forks_right);
	return ((void *)1);
}
void	*thinking(t_thread_data *data)
{
	if (!if_philo_is_dead(data))
		return (NULL);
	choose_print_routine(data, "thinking");
	return ((void *)1);
}

void	*philo_routine(void *arg)
{
	t_thread_data *data;

	data = (t_thread_data *)arg;
	thinking(data);
	while (1)
	{
		usleep(100);
		if (data->id % 2 == 0)
			usleep(100);
		if (!eating(data))
			return (NULL);
		if (!sleeping(data))
			return (NULL);
		if (!thinking(data))
			return (NULL);
	}
}

t_thread_data *init_data(t_threads *philo)
{
	t_thread_data 	*data;
	int				i;

	i = 0;
	data = (t_thread_data *)malloc(sizeof(t_thread_data) * philo->number_philo);
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
		i++;
	}
	return (data);
}

pthread_t *malloc_threads(int number_of_philo)
{
	pthread_t *threads;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * number_of_philo);
	return (threads);
}

void	init_mutex(t_threads *philo, int number_of_philo)
{
	int				i;

	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * number_of_philo);
	philo->mutex_last_eat = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * number_of_philo);
	philo->mutex_eating_count = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
			number_of_philo);
	i = 0;
	while (i < number_of_philo)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		pthread_mutex_init(&philo->mutex_last_eat[i], NULL);
		pthread_mutex_init(&philo->mutex_eating_count[i], NULL);
		i++;
	}
	pthread_mutex_init(&philo->mutex_print, NULL);
	pthread_mutex_init(&philo->mutex_death, NULL);
}

void	init_threads(t_threads *philo)
{
	int	i;

	i = 0;
	philo->timestamp = get_current_time();
	while (i < philo->data[0].number_philo)
	{
		philo->data[i].timestamp = philo->timestamp;
		philo->data[i].last_eat_time = get_current_time();
		pthread_create(&philo->threads[i], NULL, philo_routine, &philo->data[i]);
		i++;
	}
}

void	init_philo_data(t_threads *philo)
{	
	philo->philo_died = 0;
	init_mutex(philo, philo->number_philo);
	philo->data = init_data(philo);
	philo->threads = malloc_threads(philo->number_philo);
	init_threads(philo);
}

void end_of_threads(t_threads *philo)
{
	int		i;
	void	*return_value;

	i = 0;
	while (i < philo->number_philo)
	{
		pthread_join(philo->threads[i], &return_value);
		i++;
	}
}

void	*set_argv(t_threads *philo, char **argv, int argc)
{
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

int	main(int argc, char *argv[])
{
	t_threads		philo;
	int				i;
	int				count;

	if (argc != 5 && argc != 6)
	{
		printf("Usage: ./philo [numbers of philosopher] [time to die] ");
		printf("[time to eat] [time to sleep] ");
		printf("[number_of_times_each_philosopher_must_eat](optional)\n");
	}
	else
	{	
		count = 0;
		if(!set_argv(&philo, argv, argc))
		{
			printf("Error argv\n");
			return (1);
		}
		init_philo_data(&philo);
		i = 0;
		while (1)
		{
			usleep(100);
			pthread_mutex_lock(philo.data[i].mutex_eating_count);
			if (philo.data[i].eating_count == philo.eating_count && \
					philo.eating_count != 0 && \
					philo.data[i].ate_everything != 1)
			{
				count++;
				philo.data[i].ate_everything = 1;
			}
			pthread_mutex_unlock(philo.data[i].mutex_eating_count);
			pthread_mutex_lock(&philo.mutex_last_eat[i]);
			if (get_current_time() - philo.data[i].last_eat_time >= \
					(unsigned long)philo.time_to_die || count == philo.number_philo)
			{
				pthread_mutex_unlock(&philo.mutex_last_eat[i]);
				pthread_mutex_lock(&philo.mutex_death);
				philo.philo_died = 1;
				pthread_mutex_unlock(&philo.mutex_death);
				if (count != philo.number_philo)
					choose_print_routine(&philo.data[i], "died");
				break ;
			}
			pthread_mutex_unlock(&philo.mutex_last_eat[i]);
			i++;
			if (i == philo.number_philo)
				i = 0;
		}
		end_of_threads(&philo);
	}
	return (0);
}

/* protection des malloc , mutex et thread*/
/* free les mallocs */
/* destroy mutex */
/* normer */
