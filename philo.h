/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:36:27 by sojung            #+#    #+#             */
/*   Updated: 2022/05/30 16:11:03 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>

# define MAX_PHILO 200

typedef struct s_philo
{
	struct s_info	*info;
	int				index;
	int				left_fork;
	int				right_fork;
	int				n_eat;
	long long		last_eat_time;
	pthread_t		thread;
}	t_philo;

typedef struct s_info
{
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		n_philo;
	long long		min_eat;
	long long		start_time;
	int				is_dead;
	int				is_full;
	t_philo			philos[MAX_PHILO];
	pthread_mutex_t	fork[MAX_PHILO];
	pthread_mutex_t	write;
	pthread_mutex_t	eat;
	pthread_mutex_t	dead;
}	t_info;

/**
/	TIME
**/

long long	current_time(void);
int			time_lapse(t_philo *philo, long long duration);

/**
/	UTIL
**/

int			error(char *msg);
void		writing(t_philo *philo, char *msg);
int			check_finish(t_info *info);
int			check_dead(t_info *info);
int			check_full(t_info *info);

/**
/	INIT
**/

int			init_info(t_info *info, char **argv);
int			init_mutex(t_info *info);
void		init_philos(t_info *info);
int			init_threads(t_info *info);
int			create_threads(t_philo *philo, void *(*routine)(void *));

/**
/	CHECK_ARG
**/

int			check_arg(int argc, char **argv);
int			is_digit(char **argv);
long long	ft_atol(char *nptr);

/**
/	ROUTINE
**/

void		*routine(void *ptr);
void		*routine_solo(void *ptr);
int			continue_condition(t_philo *philo);

/**
/	FINISH
**/

int			destroy_mutexes(t_info *info);
int			wait_threads(t_info *info);

/**
/	ACTION
**/

int			philo_eat(t_philo *philo);
int			philo_eat_2(t_philo *philo);
int			philo_sleep(t_philo *philo);
int			philo_think(t_philo *philo);

/**
/	FORKS
**/

int			take_forks(t_philo *philo);
int			take_forks_2(t_philo *philo);
int			take_forks_solo(t_philo *philo);
int			eating(t_philo *philo);

#endif
