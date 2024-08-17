/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:31:28 by judetre           #+#    #+#             */
/*   Updated: 2024/08/17 16:23:08 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# include <sys/time.h>
# include <stddef.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_thread_data
{
	int				id;
	int				number_philo;
	unsigned long	last_eat_time;
	int 			time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*forks_left;
	pthread_mutex_t	*forks_right;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*mutex_death;
	pthread_mutex_t	*mutex_last_eat;
	pthread_mutex_t	*mutex_eating_count;
	unsigned long	timestamp;
	int				eating_count;
	int 			*philo_died;
	int				ate_everything;
}				t_thread_data;

typedef struct	s_threads
{
	pthread_t		*threads;
	t_thread_data	*data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_death;
	pthread_mutex_t	*mutex_last_eat;
	pthread_mutex_t	*mutex_eating_count;
	unsigned long 	timestamp;
	int				number_philo;
	int 			time_to_die;
	int 			time_to_eat;
	int				time_to_sleep;
	int				eating_count;
	int				philo_died;
}				t_threads;
int ft_strcmp(char *s1, char *s2);
void    init_philo_data(t_threads *philo);
unsigned long get_current_time(void);
void    init_threads(t_threads *philo);
#endif
