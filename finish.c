/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:14:02 by sojung            #+#    #+#             */
/*   Updated: 2022/05/26 18:37:29 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutexes(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		if (pthread_mutex_destroy(&info->fork[i]))
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&info->eat))
		return (1);
	if (pthread_mutex_destroy(&info->dead))
		return (1);
	if (pthread_mutex_destroy(&info->write))
		return (1);
	return (0);
}

int	wait_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		if (pthread_join(info->philos[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}
