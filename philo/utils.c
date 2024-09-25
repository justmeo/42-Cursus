/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:01:58 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/09/25 17:26:51 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_fork(t_philo *philo, int fork_id)
{
	int	grabbed;

	grabbed = 0;
	if (!grabbed)
	{
		pthread_mutex_lock(&philo->args->forks_locker[fork_id]);
		if (philo->args->forks[fork_id] == 0)
			grabbed = 1;
		if (grabbed)
			philo->args->forks[fork_id] = 1;
		pthread_mutex_unlock(&philo->args->forks_locker[fork_id]);
		if (!grabbed)
			usleep(100);
	}
	
}

void	drop_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_lock(&philo->args->forks_locker[fork_id]);
	philo->args->forks[fork_id] = 0;
	pthread_mutex_unlock(&philo->args->forks_locker[fork_id]);
}

void	philos_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (!philo->args->dead && philo->args->end_ate < philo->args->n_philos)
	{
		grab_fork(philo, (philo->id) - 1);
		// pthread_mutex_lock(&philo->forks_locker[(philo->id) - 1]);
		// Take left fork
		print_time(philo, "has taken a fork", 0);
		// pthread_mutex_lock(&philo->forks_locker[(philo->id) % philo->args->n_philos]); // Take right fork
		grab_fork(philo, (philo->id) % philo->args->n_philos);
		print_time(philo, "has taken a fork", 0);
		print_time(philo, "is eating", 0); // Start eating
		philo->last_meal = timing();
		ft_time_usleep(philo->args->timetoeat);
		// Sleep while eating
		// pthread_mutex_unlock(&philo->forks_locker[(philo->id)   
		// 		% philo->args->n_philos]); // Release right fork
		// pthread_mutex_unlock(&philo->forks_locker[(philo->id)
		// 		- 1]);                     // Release left fork
		drop_fork(philo, (philo->id) - 1);
		drop_fork(philo, (philo->id) % philo->args->n_philos);
		if (++philo->ate == philo->args->n_timeeat)
			// Check if eating requirement met
			philo->args->end_ate++;
		if (!philo->args->dead)
		{
			print_time(philo, "is sleeping", 0);
			ft_time_usleep(philo->args->timetosleep); // Sleep
			print_time(philo, "is thinking", 0);        // Think
		}
	}
}

unsigned long	timing(void)
{
	struct timeval	current_time;
	unsigned long	milliseconds;
	unsigned long	seconds_in_ms;
	unsigned long	microseconds_in_ms;

	gettimeofday(&current_time, NULL);
	seconds_in_ms = current_time.tv_sec * 1000;
	microseconds_in_ms = current_time.tv_usec / 1000;
	milliseconds = seconds_in_ms + microseconds_in_ms;
	return (milliseconds);
}

unsigned long	passed_time(t_philo *philos)
{
	unsigned long	current_time;
	unsigned long	elapsed_time;

	current_time = timing();
	elapsed_time = current_time - philos->init_time;
	return (elapsed_time);
}

void	print_time(t_philo *philo, char *text, int is_dead)
{
	pthread_mutex_lock(philo->print_locker);
	if (is_dead != 2)
		printf("%lums	%d	%s.\n", passed_time(philo), philo->id, text);
	if (is_dead == 1 || is_dead == 2)
		return ;
	pthread_mutex_unlock(philo->print_locker);
}

int	ft_atoi(char *str)
{
	long	n;
	int		s;

	s = 1;
	n = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		n = (n * 10) + (*str++ - '0');
	if (n > INT_MAX)
		return (0);
	return (s * (int)n);
}
