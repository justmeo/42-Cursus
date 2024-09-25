/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:01:40 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/09/25 17:40:43 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	need_init(t_need *args, char **av)
{
	args->n_philos = ft_atoi(av[1]);
	args->timetodie = ft_atoi(av[2]);
	args->timetoeat = ft_atoi(av[3]);
	args->timetosleep = ft_atoi(av[4]);
	if (av[5])
		args->n_timeeat = ft_atoi(av[5]);
	else
	{
		args->n_timeeat = -1;
	}
	args->dead = 0;
	args->end_ate = 0;
}

int	prg_init(t_prg *prg, char **av)
{
	t_need	*args;
	t_philo	*philo;

	args = malloc(sizeof(t_need));
	if (!args)
		return (printf("Error init args.\n"));
	need_init(args, av);
	prg->args = args;
	philo = malloc(sizeof(t_philo) * args->n_philos);
	if (!philo)
		return (printf("Error init philos.\n"));
	args->forks = malloc(sizeof(int) * args->n_philos);
	if (!args->forks)
		return (printf("Error init forks.\n"));
	int i = 0;
	while (i < args->n_philos)
		args->forks[i++] = 0;
	prg->philo = philo;
	init_lockers(prg);
	return (0);
}

void	philo_init(t_philo *philo, t_need *args, pthread_mutex_t *forks_locker,
		pthread_mutex_t *print_locker)
{
	int	i;

	(void) forks_locker;
	i = 0;
	while (i < args->n_philos)
	{
		philo[i].ate = 0;
		philo[i].id = i + 1;
		philo[i].args = args;
		// philo[i].forks_locker = fork_locker;
		philo[i].init_time = timing();
		philo[i].last_meal = timing();
		philo[i].print_locker = print_locker;
		i++;
	}
}


void	init_lockers(t_prg *prg)
{
	// pthread_mutex_t	*forks_locker;
	pthread_mutex_t	*print_locker;
	int				i;

	prg->args->forks_locker = malloc(sizeof(pthread_mutex_t) * prg->args->n_philos);
	print_locker = malloc(sizeof(pthread_mutex_t));
	if (!prg->args->forks_locker || !print_locker)
		return ;
	i = -1;
	while (++i < prg->args->n_philos)
		if (pthread_mutex_init(&prg->args->forks_locker[i], NULL))
			return ;
	i = -1;
	while (++i < prg->args->n_philos)
		if (pthread_mutex_init(&prg->philo->dead_lock, NULL))
			return ;
	if (pthread_mutex_init(&(*print_locker), NULL))
		return ;
	philo_init(prg->philo, prg->args, prg->args->forks_locker, print_locker);
}
