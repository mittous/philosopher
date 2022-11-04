/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:04:27 by imittous          #+#    #+#             */
/*   Updated: 2022/11/01 05:33:10 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	*ft_check_death(void	*cp)
{
	t_philz		*info;
	long long	j;

	info = (t_philz *)cp;
	while (1)
	{
		sem_wait(info->f_dta->check);
		j = ft_get_time() - info->last_meal;
		sem_post(info->f_dta->check);
		if (j > info->f_dta->tmtdie)
		{
			sem_wait(info->f_dta->print);
			printf("%lld %d dead\n", ft_get_time() - info->f_dta->reference,
				info->id + 1);
			exit(0);
		}
	}
	return (0);
}

void	ft_philo_eat(t_philz *info)
{
	sem_wait(info->f_dta->fork);
	sem_wait(info->f_dta->print);
	printf ("%lld %d take fork\n", (ft_get_time() - info->f_dta->reference),
		info->id + 1);
	sem_post(info->f_dta->print);
	sem_wait(info->f_dta->fork);
	sem_wait(info->f_dta->print);
	printf ("%lld %d take fork\n", (ft_get_time() - info->f_dta->reference),
		info->id + 1);
	printf ("%lld %d is eating\n", (ft_get_time() - info->f_dta->reference),
		info->id + 1);
	sem_wait(info->f_dta->check);
	info->f_dta->check_eat++;
	info->last_meal = ft_get_time();
	sem_post(info->f_dta->check);
	sem_post(info->f_dta->print);
	ft_usleep(info->f_dta->tmtoeat);
	sem_post(info->f_dta->fork);
	sem_post(info->f_dta->fork);
}

void	*ft_routin(t_philz *info)
{
	pthread_t	philo[1];
	int			r;

	pthread_create(&philo[0], NULL, ft_check_death, &info[0]);
	if ((info->id + 1) % 2 == 0)
		usleep(300);
	while (1)
	{
		ft_philo_eat(info);
		sem_wait(info->f_dta->print);
		printf ("%lld %d is sleeping\n", (ft_get_time()
				- info->f_dta->reference), info->id + 1);
		sem_post(info->f_dta->print);
		ft_usleep(info->f_dta->tmtosleep);
		sem_wait(info->f_dta->print);
		printf ("%lld %d is thinking\n", (ft_get_time()
				- info->f_dta->reference), info->id + 1);
		sem_post(info->f_dta->print);
		sem_wait(info->f_dta->check);
		r = info->f_dta->check_eat;
		sem_post(info->f_dta->check);
		if (r == info->f_dta->philomusteat)
			exit(0);
	}
	return (0);
}

void	ft_waiting_process(t_phil *info, t_philz *philo_info)
{
	int	i;
	int	ret;

	i = 0;
	ret = -1;
	while (1)
	{
		ret = waitpid(-1, NULL, 0);
		if (ret > 0)
		{
			i = 0;
			while (i < info->philo_nmbr)
			{
				kill(philo_info->pid[i], 9);
				i++;
			}
			exit (0);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_phil		info;
	t_philz		philo_info;

	ft_parsing(av, &info, ac);
	philo_info.pid = malloc(sizeof(pid_t) * info.philo_nmbr);
	if (!philo_info.pid)
		return (0);
	sem_unlink("/sem_fork");
	sem_unlink("/sem_print");
	sem_unlink("/sem_check");
	info.fork = sem_open("/sem_fork", O_CREAT, 666, info.philo_nmbr);
	info.print = sem_open("/sem_print", O_CREAT, 666, 1);
	info.check = sem_open("/sem_check", O_CREAT, 666, 1);
	info.reference = ft_get_time();
	philo_info.id = -1;
	info.check_eat = 0;
	while (++philo_info.id < info.philo_nmbr)
	{	
		philo_info.f_dta = &info;
		philo_info.last_meal = ft_get_time();
		philo_info.pid[philo_info.id] = fork();
		if (philo_info.pid[philo_info.id] == 0)
			ft_routin(&philo_info);
	}
	ft_waiting_process(&info, &philo_info);
}
