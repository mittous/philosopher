/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:19:06 by imittous          #+#    #+#             */
/*   Updated: 2022/11/10 20:08:23 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_philo_eat(t_philz *info)
{
	pthread_mutex_lock(&info->f_dta->fork[info->id]);
	pthread_mutex_lock(&info->f_dta->print);
	printf ("%lu %d %s\n", (ft_get_time() - info->f_dta->reference),
		info->id + 1, "take fork");
	pthread_mutex_unlock(&info->f_dta->print);
	pthread_mutex_lock(&info->f_dta->fork[(info->id + 1)
		% info->f_dta->philo_nmbr]);
	pthread_mutex_lock(&info->f_dta->print);
	printf ("%lu %d %s\n", (ft_get_time() - info->f_dta->reference),
		info->id + 1, "take fork");
	pthread_mutex_unlock(&info->f_dta->print);
	pthread_mutex_lock(&info->f_dta->print);
	printf ("%lu %d %s\n", (ft_get_time() - info->f_dta->reference),
		info->id + 1, "is eating");
	pthread_mutex_unlock(&info->f_dta->print);
	pthread_mutex_lock(&info->f_dta->cheking);
	info->last_meal = ft_get_time() + info->f_dta->tmtdie;
	info->check_eat++;
	pthread_mutex_unlock(&info->f_dta->cheking);
	ft_usleep(info->f_dta->tmtoeat);
	pthread_mutex_unlock(&info->f_dta->fork[(info->id + 1)
		% info->f_dta->philo_nmbr]);
	pthread_mutex_unlock(&info->f_dta->fork[info->id]);
}

/***********************************************************/

void	*ft_routin(void *cp)
{
	t_philz	*info;

	info = (t_philz *)cp;
	if (info->id % 2 != 0)
		usleep(300);
	while (1)
	{
		ft_philo_eat(info);
		pthread_mutex_lock(&info->f_dta->print);
		printf("%ld %d is sleeping\n", ft_get_time() - info->f_dta->reference,
			info->id + 1);
		pthread_mutex_unlock(&info->f_dta->print);
		ft_usleep(info->f_dta->tmtosleep);
		pthread_mutex_lock(&info->f_dta->print);
		printf("%ld %d is thinking\n", ft_get_time() - info->f_dta->reference,
			info->id + 1);
		pthread_mutex_unlock(&info->f_dta->print);
	}
	return (0);
}

/***********************************************************/

int	ft_check_eating(t_phil **info, t_philz *philo_info)
{
	int	s;
	int	j;

	s = 0;
	while ((*info)->philomusteat != -1 && s < (*info)->philo_nmbr)
	{
		pthread_mutex_lock(&philo_info->f_dta->cheking);
		j = philo_info[s].check_eat;
		pthread_mutex_unlock(&philo_info->f_dta->cheking);
		if (j >= (*info)->philomusteat && s == (*info)->philo_nmbr - 1)
			return (1);
		if (j < (*info)->philomusteat)
			break ;
		s++;
	}
	return (0);
}

/***********************************************************/

int	ft_check_death(t_phil **info, t_philz *philo_info)
{
	int				i;
	unsigned long	j;

	while (1)
	{
		i = -1;
		while (++i < (*info)->philo_nmbr)
		{
			pthread_mutex_lock(&philo_info->f_dta->cheking);
			j = philo_info[i].last_meal;
			pthread_mutex_unlock(&philo_info->f_dta->cheking);
			if (ft_get_time() > j)
			{
				pthread_mutex_lock(&philo_info->f_dta->print);
				printf("%lu %d dead\n", ft_get_time() - (*info)->reference,
					i + 1);
				return (1);
			}
			if (ft_check_eating(info, philo_info))
				return (1);
		}
	}
	return (0);
}

/***********************************************************/

int	main(int ac, char **av)
{
	int			i;
	t_phil		*info;
	t_philz		*philo_info;
	pthread_t	*philo;

	info = malloc(sizeof(t_phil));
	if (!info)
		return (0);
	if (ft_parsing(av, &info, ac) == 0)
		return (0);
	i = 0;
	philo_info = malloc(sizeof(t_philz) * ((*info).philo_nmbr));
	if (!philo_info)
		return (0);
	philo = malloc(sizeof(pthread_t) * ((*info).philo_nmbr));
	if (!philo)
		return (0);
	(*info).fork = malloc(sizeof(pthread_mutex_t) * ((*info).philo_nmbr));
	if (!(*info).fork)
		return (0);
	creat_philo(&info, philo_info, philo);
	if (ft_check_death(&info, philo_info))
		ft_finish_prog(philo_info, philo, &info);
}
