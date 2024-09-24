/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:45:42 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/09/24 15:02:05 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_prg_args
{
	int				n_philos;
	int				t_t_d;
	int				t_t_e;
	int				t_t_s;
	int				n_t_m_e;
	int				end_ate;
	unsigned long	elapse_time;
	int				dead;
}t_prg_args;

typedef struct s_philo
{
	int				ate;
	int				id;
	t_prg_args		*args;
	unsigned long	init_time;
	unsigned long	last_meal;
	pthread_mutex_t	*forks_locker;
	pthread_mutex_t	*print_locker;
}t_philo;

typedef struct s_main_program
{
	t_prg_args	*args;
	t_philo		*philo;
}t_prg;
int	ft_prg_init(t_prg *prg, char **av);
void	ft_args_init(t_prg_args	*args, char **av);
void	ft_philos_init(t_philo *philos, t_prg_args *args,
	pthread_mutex_t	*fork_locker, pthread_mutex_t *print_locker);
// typedef struct need {
//     int				timetodie;
//     int				timetoeat;
//     int				timetosleep;
//     int				n_timeeat;
//     int				dead;
//     int				end_ate;
//     int				n_philos;
//     unsigned long	elapse_time;
// } t_need;

// typedef struct philo {
//     int				ate;
//     int				id;
//     t_need			*args;
//     unsigned long	init_time;
//     unsigned long	last_meal;
//     pthread_mutex_t	*forks_locker;
//     pthread_mutex_t	*print_locker;
// } t_philo;

// typedef struct prg {
//     t_need	*args;
//     t_philo	*philo;
// } t_prg;

// void need_init(t_need *args, char **av);
int prg_init(t_prg *prg, char **av);
// void philo_init(t_philo *philo, t_need *args, pthread_mutex_t *fork_locker, pthread_mutex_t *print_locker);
void init_lockers(t_prg *prg);
unsigned long ft_actual_time(void);
unsigned long ft_elapse_time(t_philo *philos);
void ft_print(t_philo *philo, char *text, int dead);
int ft_atoi(char *str);
void ft_is_dead(t_philo *philo);
void ft_time_usleep(int t_t);
int ft_check_input(int ac, char **av);
void philos_routine(void *p);
void	ft_philo_deleter(t_prg *p);


#endif