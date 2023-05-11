/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:11:19 by sojung            #+#    #+#             */
/*   Updated: 2022/05/30 12:44:45 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	if (take_forks(philo))
		return (1);
	pthread_mutex_lock(&philo->info->eat);
	philo->n_eat++;
	philo->last_eat_time = current_time();
	pthread_mutex_unlock(&philo->info->eat);
	writing(philo, "is eating");
	if (time_lapse(philo, philo->info->time_to_eat))
	{
		pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
	return (0);
}

int	philo_eat_2(t_philo *philo)
{
	if (take_forks_2(philo))
		return (1);
	pthread_mutex_lock(&philo->info->eat);
	writing(philo, "is eating");
	philo->n_eat++;
	philo->last_eat_time = current_time();
	pthread_mutex_unlock(&philo->info->eat);
	if (time_lapse(philo, philo->info->time_to_eat))
	{
		pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
		pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	if (continue_condition(philo))
		return (1);
	writing(philo, "is sleeping");
	if (time_lapse(philo, philo->info->time_to_sleep))
		return (1);
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (continue_condition(philo))
		return (1);
	writing(philo, "is thinking");
	return (0);
}
