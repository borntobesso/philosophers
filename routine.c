/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:22:10 by sojung            #+#    #+#             */
/*   Updated: 2022/06/01 14:11:13 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		if (continue_condition(philo))
			break ;
		if (philo->index % 2 == 0)
		{
			usleep(5000);
			if (philo_eat_2(philo))
				break ;
		}
		else if (philo->index % 2 == 1)
			if (philo_eat(philo))
				break ;
		if (philo_sleep(philo))
			break ;
		if (philo_think(philo))
			break ;
	}
	return (NULL);
}

void	*routine_solo(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	take_forks_solo(philo);
	return (NULL);
}

int	continue_condition(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->dead);
	if (philo->info->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->info->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->dead);
	pthread_mutex_lock(&philo->info->eat);
	if (philo->info->is_full == 1)
	{
		pthread_mutex_unlock(&philo->info->eat);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->eat);
	return (0);
}
