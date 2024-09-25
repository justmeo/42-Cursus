/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:45:58 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/09/25 17:58:43 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_input(int ac, char **av)
{
	if (ac < 5 || ac > 6 || ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (printf("Error: incorrect input.\n"));
	if (av[5] != NULL)
		if (ft_atoi(av[5]) <= 0)
			return (printf("Error: incorrect input.\n"));
	return (0);
}

void	ft_time_usleep(int t_t)
{
	unsigned long	start;

	start = timing();
	while (timing() - start < (unsigned long)t_t)
		usleep(20);
}

void	ft_is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
	pthread_mutex_lock(&philo->deadlock);
		
		if (timing()
			- philo[i].last_meal >= (unsigned long)philo->args->timetodie)
		{
			philo->args->dead = 1;
			print_time(&philo[i], "died", 1);
			return ;
		}
		if (philo->args->end_ate == philo->args->n_philos)
		{
			print_time(&philo[i], "died", 2);
			return ;
		}
		i = (i + 1) % philo->args->n_philos;
	}
}

void	ft_philo_deleter(t_prg *p, pthread_t *me)
{
	while (--(p->args->n_philos) > -1)
		pthread_mutex_destroy(&p->philo->args->forks_locker[p->args->n_philos]);
	pthread_mutex_destroy(&(*p->philo->print_locker));
	for (int i = 0; i < p->args->n_philos; i++) {
		pthread_join(me[i], NULL);
	}
	free(p->philo->args->forks_locker);
	free(p->philo->print_locker);
	free(p->args);
	free(p->philo);
	free(p);
	
}

int	main(int ac, char **av)
{
	pthread_t	*thr;
	t_prg		*prg;
	int			i;

	if (ft_check_input(ac, av))
		return (0);
	prg = malloc(sizeof(t_prg));
	thr = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	if (!prg || !thr)
		return (printf("Error allocating memory."));
	prg_init(prg, av);
	i = -1;
	while (++i < prg->args->n_philos)
	{
		if (pthread_create(&thr[i], NULL, (void *)&philos_routine,
				(void *)&prg->philo[i]))
			return (printf("Error creating threads."));
		usleep(100);
	}
	ft_is_dead(prg->philo);
	ft_philo_deleter(prg, thr);
	free(thr);
	return (0);
}
