/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:28:42 by sojung            #+#    #+#             */
/*   Updated: 2022/05/26 18:37:39 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->left_fork]);
	if (continue_condition(philo))
	{
		pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
		return (1);
	}
	writing(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->fork[philo->right_fork]);
	if (continue_condition(philo))
	{
		pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
		return (1);
	}
	writing(philo, "has taken a fork");
	return (0);
}

int	take_forks_2(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->right_fork]);
	if (continue_condition(philo))
	{
		pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
		return (1);
	}
	writing(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->fork[philo->left_fork]);
	if (continue_condition(philo))
	{
		pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
		pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
		return (1);
	}
	writing(philo, "has taken a fork");
	return (0);
}

int	take_forks_solo(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->right_fork]);
	writing(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
	usleep(philo->info->time_to_die * 1000);
	return (1);
}
