/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:02:59 by sojung            #+#    #+#             */
/*   Updated: 2022/05/26 18:37:33 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	time_lapse(t_philo *philo, long long duration)
{
	long long	start_time;

	start_time = current_time();
	while (1)
	{
		if (continue_condition(philo))
			return (1);
		if (current_time() - start_time >= duration)
			break ;
		usleep(50);
	}
	return (0);
}
