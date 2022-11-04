/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:21:27 by imittous          #+#    #+#             */
/*   Updated: 2022/11/02 21:52:02 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_lock_fork(char *s, t_philz *info, int i, int id)
{
	pthread_mutex_lock(&info->f_dta->end);
	if (info->f_dta->stop == true)
		return (1);
	pthread_mutex_unlock(&info->f_dta->end);
	pthread_mutex_lock(&info->f_dta->fork[i]);
	pthread_mutex_lock(&info->f_dta->print);
	printf ("%lu %d %s\n", (ft_get_time() - info->f_dta->reference),
		id + 1, s);
	pthread_mutex_unlock(&info->f_dta->print);
	return (0);
}

/***********************************************************/

int	ft_print_and_lock(char *s, t_philz *info, int id)
{
	// pthread_mutex_lock(&info->f_dta->end);
	// if (info->f_dta->stop == true)
	// 	return (1);
	// pthread_mutex_unlock(&info->f_dta->end);
	pthread_mutex_lock(&info->f_dta->print);
	printf ("%lu %d %s\n", (ft_get_time() - info->f_dta->reference),
		id + 1, s);
	pthread_mutex_unlock(&info->f_dta->print);
	return (0);
}

/***********************************************************/

void	ft_unlock_fork(t_philz *info, int i)
{
	pthread_mutex_unlock(&info->f_dta->fork[i]);
}

/***********************************************************/

int	ft_finish_prog(t_philz *philo_info, pthread_t *philo, t_phil *info)
{
	int	i;

	i = -1;
	usleep(2000);
	while (++i < info->philo_nmbr)
		pthread_mutex_destroy(&info->fork[i]);
	pthread_mutex_destroy(&info->cheking);
	free(philo_info);
	free(philo);
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->end);
	return (0);
}

/***********************************************************/

void	*creat_philo(t_phil *info, t_philz *philo_info, pthread_t *philo)
{
	int	i;

	i = -1;
	while (++i < info->philo_nmbr)
		pthread_mutex_init(&info->fork[i], NULL);
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->cheking, NULL);
	pthread_mutex_init(&info->end, NULL);
	info->reference = ft_get_time();
	i = -1;
	info->stop = false;
	while (++i < info->philo_nmbr)
	{
		philo_info[i].f_dta = info;
		philo_info[i].id = i;
		philo_info[i].check_eat = 0;
		philo_info[i].last_meal = ft_get_time();
		pthread_create(&philo[i], NULL, ft_routin, &philo_info[i]);
		usleep(100);
		pthread_detach(philo[i]);
	}
	return (0);
}
