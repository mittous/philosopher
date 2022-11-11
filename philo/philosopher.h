/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:21:33 by imittous          #+#    #+#             */
/*   Updated: 2022/11/10 16:20:50 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>

typedef struct phil{
	pthread_mutex_t	print;
	pthread_mutex_t	cheking;
	pthread_mutex_t	*fork;
	unsigned long	reference;
	int				philo_nmbr;
	unsigned long	tmtdie;
	int				tmtoeat;
	int				tmtosleep;
	int				philomusteat;
}	t_phil;

typedef struct philz{
	int				id;
	unsigned long	last_meal;
	t_phil			*f_dta;
	int				check_eat;
}	t_philz;

/* ######### main_philo.c ######### */
void			ft_philo_eat(t_philz *info);
void			*ft_routin(void *cp);
int				ft_check_death(t_phil **info, t_philz *philo_info);
/* ######### main_philo.c ######### */

/* ######### philo_utils.c ######### */
long			ft_atoi(char *str);
int				ft_parsing(char **av, t_phil **info, int ac);
unsigned long	ft_get_time(void);
void			ft_usleep(unsigned long time);
/* ######### philo_utils.c ######### */

/* ######### philo_utils1.c ######### */
int				ft_lock_fork(char *s, t_philz *info, int i, int id);
int				ft_print_and_lock(char *s, t_philz *info, int id);
void			ft_unlock_fork(t_philz *info, int i);
int				ft_finish_prog(t_philz *philo_io, pthread_t *phi,
					t_phil **info);
void			*creat_philo(t_phil **info, t_philz *philo_nfo,
					pthread_t *phio);
/* ######### philo_utils1.c ######### */

#endif
