/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:05:27 by sojung            #+#    #+#             */
/*   Updated: 2022/05/30 16:11:35 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5)
		return (error("Insufficient argument(s)"));
	else if (argc > 6)
		return (error("Too many arguments"));
	if (is_digit(argv))
		return (error("Numeric values required"));
	i = 1;
	if (ft_atol(argv[i]) > 200)
		return (error("Maximum value of philosophers is 200"));
	while (argv[i])
	{
		if (ft_atol(argv[i]) <= 0)
			return (error("Positive values required"));
		j = 0;
		while (argv[i][j])
			j++;
		if (j > 18)
			return (error("Invalid argument"));
		i++;
	}
	return (0);
}

int	is_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long long	ft_atol(char *nptr)
{
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * res);
}
