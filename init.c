/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:00:55 by sojung            #+#    #+#             */
/*   Updated: 2022/05/30 16:06:33 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(t_info *info, char **argv)
{
	int	i;

	info->min_eat = -1;
	i = 1;
	while (argv[i])
	{
		if (i == 1)
			info->n_philo = ft_atol(argv[i]);
		else if (i == 2)
			info->time_to_die = ft_atol(argv[i]);
		else if (i == 3)
			info->time_to_eat = ft_atol(argv[i]);
		else if (i == 4)
			info->time_to_sleep = ft_atol(argv[i]);
		else if (i == 5)
			info->min_eat = ft_atol(argv[i]);
		i++;
	}
	info->is_dead = 0;
	info->is_full = 0;
	if (init_mutex(info))
		return (error("Mutex init"));
	init_philos(info);
	return (0);
}

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&info->write, NULL))
		return (1);
	if (pthread_mutex_init(&info->eat, NULL))
		return (1);
	if (pthread_mutex_init(&info->dead, NULL))
		return (1);
	return (0);
}

void	init_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		info->philos[i].info = info;
		info->philos[i].index = i;
		info->philos[i].left_fork = (i + 1) % info->n_philo;
		info->philos[i].right_fork = i;
		info->philos[i].n_eat = 0;
		i++;
	}
}

int	init_threads(t_info *info)
{
	int	i;

	i = -1;
	info->start_time = current_time();
	while (++i < info->n_philo)
	{
		info->philos[i].last_eat_time = current_time();
		if (info->n_philo == 1)
		{
			if (create_threads(&info->philos[i], &routine_solo))
				return (1);
		}
		else
		{
			if (create_threads(&info->philos[i], &routine))
				return (1);
		}
	}
	return (0);
}

int	create_threads(t_philo *philo, void *(*routine)(void *))
{
	if (pthread_create(&philo->thread, NULL, routine, (void *)philo))
	{
		error("Creating threads");
		return (1);
	}
	return (0);
}
