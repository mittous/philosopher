/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:06:22 by imittous          #+#    #+#             */
/*   Updated: 2022/11/10 19:49:57 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct phil{
	sem_t			*print;
	sem_t			*fork;
	sem_t			*check;
	long			reference;
	int				philo_nmbr;
	int				tmtdie;
	int				tmtoeat;
	int				tmtosleep;
	int				philomusteat;
	int				check_eat;
}	t_phil;

typedef struct philz{
	int			id;
	long long	last_meal;
	pid_t		*pid;
	t_phil		*f_dta;
}	t_philz;

/* ######### main_philo.c ######### */
void		*ft_check_death(void	*cp);
void		ft_philo_eat(t_philz **info);
void		*ft_routin(t_philz **info);
void		ft_waiting_process(t_phil **info, t_philz **philo_info);
/* ######### main_philo.c ######### */

/* ######### philo_utils.c ######### */
long		ft_atoi(char *str);
int			ft_parsing(char **av, t_phil **info, int ac, t_philz **philo_info);
long long	ft_get_time(void);
void		ft_usleep(long long time);
/* ######### philo_utils.c ######### */

#endif