/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:31:28 by judetre           #+#    #+#             */
/*   Updated: 2024/08/19 12:37:37 by judetre          ###   ########.fr       */
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

typedef struct s_thread_data
{
	int				id;
	int				*err;
	int				number_philo;
	unsigned long	last_eat_time;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*forks_left;
	pthread_mutex_t	*forks_right;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*mutex_death;
	pthread_mutex_t	*mutex_last_eat;
	pthread_mutex_t	*mutex_eating_count;
	unsigned long	timestamp;
	int				eating_count;
	int				*philo_died;
	int				ate_everything;
}				t_thread_data;

typedef struct s_threads
{
	pthread_t		*threads;
	t_thread_data	*data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mutex_last_eat;
	pthread_mutex_t	*mutex_eating_count;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_death;
	int				count_mutex[5];
	int				count_threads;
	unsigned long	timestamp;
	int				number_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating_count;
	int				philo_died;
	int				err;
}				t_threads;

/************************************** UTILS ****************************/

void			*ft_memset(void *s, int c, size_t n);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);
int				ft_isdigit(char *str);
long			ft_atoi(char *str);

/************************************** PRINT ****************************/

void			print_err_argv(void);
void			choose_print_routine(t_thread_data *data, char *str);
void			print(t_thread_data *data, char *str);

/************************************** PHILO_ACTION *************************/

void			*wait(int time_wait, t_thread_data *data);
void			*thinking(t_thread_data *data);
void			*eating(t_thread_data *data);
void			*sleeping(t_thread_data *data);

/************************************** MONITORING *************************/

void			monitoring(t_threads *philo);

/************************************** INIT ******************************/

int				init_mutex(t_threads *philo, int number_of_philo);
t_thread_data	*init_data(t_threads *philo);
pthread_t		*malloc_threads(int number_of_philo);
int				init_threads(t_threads *philo);

/************************************** SET ******************************/

void			set_data(t_threads *philo, t_thread_data *data);
void			*set_argv(t_threads *philo, char **argv, int argc);

/************************************** FREE ******************************/

void			free_malloc(t_threads *philo);
void			free_all(t_threads *philo);

/************************************** FORKS_UTILS *************************/

void			*take_left_first(t_thread_data *data);
void			*take_right_first(t_thread_data *data);
void			*choose_order_take_forks(t_thread_data *data);

/************************************** PHILO_UTILS *************************/

unsigned long	get_current_time(void);
void			*if_philo_is_dead(t_thread_data *data);
int				if_philo_is_solo(t_thread_data *data);
void			unlock_forks(t_thread_data *data);

/************************************** PHILO_ROUTINE ***********************/

void			*philo_routine(void *arg);

#endif
