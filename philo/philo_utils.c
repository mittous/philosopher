/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:24:05 by imittous          #+#    #+#             */
/*   Updated: 2022/11/07 15:45:20 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		base = (base * 10) + (str[i] - 48);
		if (base * sign > 2147483647 || base * sign < -2147483648)
			return (-1);
		i++;
	}
	if (str[i])
		return (-1);
	return (base * sign);
}

/***********************************************************/

int	ft_parsing(char **av, t_phil **info, int ac)
{
	if (ac < 5 || ac > 6)
		return (0);
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < -1 || ft_atoi(av[3]) < -1
		|| ft_atoi(av[4]) < -1)
		return (0);
	if (ft_atoi(av[1]) > 0)
		(*info)->philo_nmbr = ft_atoi(av[1]);
	if (ft_atoi(av[2]) >= 0)
		(*info)->tmtdie = ft_atoi(av[2]);
	if (ft_atoi(av[3]) >= 0)
		(*info)->tmtoeat = ft_atoi(av[3]);
	if (ft_atoi(av[4]) >= 0)
		(*info)->tmtosleep = ft_atoi(av[4]);
		(*info)->philomusteat = -1;
	if (av[5])
		if (ft_atoi(av[5]) >= 0)
			(*info)->philomusteat = ft_atoi(av[5]);
	return (1);
}

/***********************************************************/

unsigned long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

/***********************************************************/

void	ft_usleep(unsigned long time)
{
	unsigned long	t_tosleep;

	t_tosleep = ft_get_time() + time;
	while (ft_get_time() < t_tosleep)
		usleep(120);
}
