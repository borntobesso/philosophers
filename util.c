/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:07:51 by sojung            #+#    #+#             */
/*   Updated: 2022/06/01 14:11:57 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *msg)
{
	printf("Error : ");
	printf("%s\n", msg);
	return (1);
}

void	writing(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->write);
	printf("%lld ", (current_time() - philo->info->start_time));
	printf("%d ", (philo->index + 1));
	printf("%s\n", msg);
	pthread_mutex_unlock(&philo->info->write);
}

int	check_finish(t_info *info)
{
	while (1)
	{
		if (check_dead(info))
			return (1);
		if (info->min_eat != -1)
			if (check_full(info))
				return (1);
		usleep(50);
	}
	return (0);
}

int	check_dead(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		pthread_mutex_lock(&info->eat);
		if (current_time() - info->philos[i].last_eat_time \
				> info->time_to_die)
		{
			pthread_mutex_unlock(&info->eat);
			pthread_mutex_lock(&info->dead);
			info->is_dead = 1;
			pthread_mutex_unlock(&info->dead);
			writing(&info->philos[i], "died");
			return (1);
		}
		pthread_mutex_unlock(&info->eat);
		i++;
	}
	return (0);
}

int	check_full(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		pthread_mutex_lock(&info->eat);
		if (info->philos[i].n_eat < info->min_eat)
		{
			pthread_mutex_unlock(&info->eat);
			return (0);
		}
		pthread_mutex_unlock(&info->eat);
		i++;
	}
	pthread_mutex_lock(&info->eat);
	info->is_full = 1;
	pthread_mutex_unlock(&info->eat);
	return (1);
}
