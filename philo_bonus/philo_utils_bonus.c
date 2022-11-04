/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:05:45 by imittous          #+#    #+#             */
/*   Updated: 2022/11/01 05:46:14 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	base;

	sign = 1;
	i = 0;
	base = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		exit (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		base = (base * 10) + (str[i] - 48);
		if (base * sign > 2147483647 || base * sign < -2147483648)
			exit (1);
		i++;
	}
	if (str[i])
		exit (1);
	return (base * sign);
}

/***********************************************************/

int	ft_parsing(char **av, t_phil *info, int ac)
{
	if (ac < 5 || ac > 6)
		exit (1);
	info->philo_nmbr = ft_atoi(av[1]);
	info->tmtdie = ft_atoi(av[2]);
	info->tmtoeat = ft_atoi(av[3]);
	info->tmtosleep = ft_atoi(av[4]);
	info->philomusteat = -1;
	if (av[5])
		info->philomusteat = ft_atoi(av[5]);
	return (1);
}

/***********************************************************/

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

/***********************************************************/

void	ft_usleep(long long time)
{
	long long	t_tosleep;

	t_tosleep = ft_get_time() + time;
	while (ft_get_time() < t_tosleep)
		usleep(100);
}
