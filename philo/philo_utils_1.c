/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:19:45 by imittous          #+#    #+#             */
/*   Updated: 2022/11/10 20:06:39 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_lock_fork(char *s, t_philz *info, int i, int id)
{
	pthread_mutex_lock(&info->f_dta->fork[i]);
	pthread_mutex_lock(&info->f_dta->print);
	printf ("%lu %d %s\n", (ft_get_time() - info->f_dta->reference),
		id + 1, s);
	pthread_mutex_unlock(&info->f_dta->print);
	return (0);
}

/***********************************************************/

int	ft_finish_prog(t_philz *philo_info, pthread_t *philo, t_phil **info)
{
	int	i;

	i = -1;
	while (++i < (*info)->philo_nmbr)
		pthread_mutex_destroy(&(*info)->fork[i]);
	pthread_mutex_destroy(&(*info)->cheking);
	free(philo_info);
	free(philo);
	pthread_mutex_destroy(&(*info)->print);
	return (0);
}

/***********************************************************/

void	*creat_philo(t_phil **info, t_philz *philo_info, pthread_t *philo)
{
	int	i;

	i = -1;
	while (++i < (*info)->philo_nmbr)
		pthread_mutex_init(&(*info)->fork[i], NULL);
	pthread_mutex_init(&(*info)->print, NULL);
	pthread_mutex_init(&(*info)->cheking, NULL);
	(*info)->reference = ft_get_time();
	i = -1;
	while (++i < (*info)->philo_nmbr)
	{
		philo_info[i].f_dta = (*info);
		philo_info[i].id = i;
		philo_info[i].check_eat = 0;
		philo_info[i].last_meal = ft_get_time() + (*info)->tmtdie;
		pthread_create(&philo[i], NULL, ft_routin, &philo_info[i]);
	}
	return (0);
}
