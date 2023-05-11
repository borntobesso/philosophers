/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:31:58 by sojung            #+#    #+#             */
/*   Updated: 2022/05/30 16:06:46 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (check_arg(argc, argv))
		return (1);
	if (init_info(&info, argv))
		return (1);
	if (init_threads(&info))
		return (1);
	if (check_finish(&info))
	{
		if (wait_threads(&info))
			return (1);
		if (destroy_mutexes(&info))
			return (1);
	}
	return (0);
}
