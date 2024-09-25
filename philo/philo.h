/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:45:42 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/09/25 17:45:40 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct need
{
	int				timetodie;
	int				timetoeat;
	int				timetosleep;
	int				n_timeeat;
	int				dead;
	int				end_ate;
	int				n_philos;
	unsigned long	elapse_time;
	int				*forks;
	pthread_mutex_t	*forks_locker;
	// pthread_mutex_t end_ate_mutex;  // Mutex to protect end_ate
    // pthread_mutex_t dead_mutex;
}					t_need;

typedef struct philo
{
	int				ate;
	int				id;
	t_need			*args;
	unsigned long	init_time;
	unsigned long	last_meal;
	pthread_mutex_t	*print_locker;
	pthread_mutex_t dead_lock;
}					t_philo;

typedef struct prg
{
	t_need			*args;
	t_philo			*philo;
}					t_prg;

void				need_init(t_need *args, char **av);
int					prg_init(t_prg *prg, char **av);
void				philo_init(t_philo *philo, t_need *args,
						pthread_mutex_t *fork_locker,
						pthread_mutex_t *print_locker);
void				init_lockers(t_prg *prg);
unsigned long		timing(void);
unsigned long		passed_time(t_philo *philos);
void				print_time(t_philo *philo, char *text, int is_dead);
int					ft_atoi(char *str);
void				ft_is_dead(t_philo *philo);
void				ft_time_usleep(int t_t);
int					ft_check_input(int ac, char **av);
void				philos_routine(void *p);
void				ft_philo_deleter(t_prg *p, pthread_t *me);

#endif