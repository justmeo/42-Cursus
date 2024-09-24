# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
#include "philo.h"

int	ft_prg_init(t_prg *prg, char **av)
{
	t_prg_args	*args;
	t_philo		*philos;

	args = malloc(sizeof(t_prg_args));
	if (!args)
		return (printf("Error init args.\n"));
	ft_args_init(args, av);
	prg->args = args;
	philos = malloc(sizeof(t_philo) * args->n_philos);
	if (!philos)
		return (printf("Error init philos.\n"));
	prg->philo = philos;
	init_lockers(prg);
	return (0);
}

void	ft_args_init(t_prg_args	*args, char **av)
{
	args->n_philos = ft_atoi(av[1]);
	args->t_t_d = ft_atoi(av[2]);
	args->t_t_e = ft_atoi(av[3]);
	args->t_t_s = ft_atoi(av[4]);
	if (av[5])
		args->n_t_m_e = ft_atoi(av[5]);
	else
		args->n_t_m_e = -1;
	args->dead = 0;
	args->end_ate = 0;
}

//No more data race. =D
void	init_lockers(t_prg *prg)
{
	pthread_mutex_t	*fork_locker;
	pthread_mutex_t	*print_locker;
	int				i;

	fork_locker = malloc(sizeof(pthread_mutex_t) * prg->args->n_philos);
	print_locker = malloc(sizeof(pthread_mutex_t));
	if (!fork_locker || !print_locker)
		return ;
	i = -1;
	while (++i < prg->args->n_philos)
		if (pthread_mutex_init(&fork_locker[i], NULL))
			return ;
	if (pthread_mutex_init(&(*print_locker), NULL))
		return ;
	ft_philos_init(prg->philo, prg->args, fork_locker, print_locker);
}

void	ft_philos_init(t_philo *philos, t_prg_args *args,
	pthread_mutex_t	*fork_locker, pthread_mutex_t *print_locker)
{
	int	i;

	i = -1;
	while (++i < args->n_philos)
	{
		philos[i].ate = 0;
		philos[i].id = i + 1;
		philos[i].args = args;
		philos[i].forks_locker = fork_locker;
		philos[i].init_time = ft_actual_time();
		philos[i].last_meal = ft_actual_time();
		philos[i].print_locker = print_locker;
	}
}

void	ft_philo_deleter(t_prg *p)
{
	while (--(p->args->n_philos) > -1)
		pthread_mutex_destroy(&p->philo->forks_locker[p->args->n_philos]);
	pthread_mutex_destroy(&(*p->philo->print_locker));
	free(p->philo->forks_locker);
	free(p->philo->print_locker);
	free(p->args);
	free(p->philo);
	free(p);
}
unsigned long	ft_actual_time(void)
{
	struct timeval	time;
	unsigned long	ret;

	gettimeofday(&time, NULL);
	ret = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (ret);
}

unsigned long	ft_elapse_time(t_philo	*philos)
{
	unsigned long	ret;

	ret = ft_actual_time() - philos->init_time;
	return (ret);
}

void	ft_print(t_philo *philo, char *text, int dead)
{
	pthread_mutex_lock(philo->print_locker);
	if (dead != 2)
		printf("%lums	%d	%s.\n", ft_elapse_time(philo), philo->id, text);
	if (dead == 1 || dead == 2)
		return ;
	pthread_mutex_unlock(philo->print_locker);
}

int	ft_atoi(char *str)
{
	long	n;
	int		s;

	s = 1;
	n = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - 48);
		str++;
	}
	if (n > INT32_MAX)
		return (0);
	return (s * (int)n);
}

int	ft_check_input(int ac, char **av)
{
	if (ac < 5 || ac > 6 || ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (printf("Error: icorrect input.\n"));
	if (av[5] != NULL)
		if (ft_atoi(av[5]) <= 0)
			return (printf("Error: icorrect input.\n"));
	return (0);
}
void	ft_philos_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (!philo->args->dead && philo->args->end_ate < philo->args->n_philos)
	{
		pthread_mutex_lock(&philo->forks_locker[(philo->id) - 1]);
		ft_print(philo, "has taken a fork", 0);
		pthread_mutex_lock(&philo->forks_locker[(philo->id)
			% philo->args->n_philos]);
		ft_print(philo, "has taken a fork", 0);
		ft_print(philo, "is eating", 0);
		philo->last_meal = ft_actual_time();
		ft_time_usleep(philo->args->t_t_e);
		pthread_mutex_unlock(&philo->forks_locker[(philo->id)
			% philo->args->n_philos]);
		pthread_mutex_unlock(&philo->forks_locker[(philo->id) - 1]);
		if (++philo->ate == philo->args->n_t_m_e)
			philo->args->end_ate++;
		if (!philo->args->dead)
		{
			ft_print(philo, "is sleeping", 0);
			ft_time_usleep(philo->args->t_t_s);
			ft_print(philo, "is thinking", 0);
		}
	}
}

void	ft_time_usleep(int t_t)
{
	unsigned long	start;

	start = ft_actual_time();
	while (ft_actual_time() - start < (unsigned long)t_t)
		usleep(20);
}

void	ft_is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (ft_actual_time() - philo[i].last_meal
			>= (unsigned long)philo->args->t_t_d)
		{
			philo->args->dead = 1;
			ft_print(&philo[i], "died", 1);
			return ;
		}
		if (philo->args->end_ate == philo->args->n_philos)
		{
			ft_print(&philo[i], "died", 2);
			return ;
		}
		i = (i + 1) % philo->args->n_philos;
	}
}
int	main(int ac, char **av)
{
	pthread_t		*thr;
	t_prg			*prg;
	int				i;

	if (ft_check_input(ac, av))
		return (0);
	prg = malloc(sizeof(t_prg));
	thr = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	if (!prg || !thr)
		return (printf("Error allocating memory."));
	ft_prg_init(prg, av);
	i = -1;
	while (++i < prg->args->n_philos)
	{
		if (pthread_create(&thr[i], NULL, (void *)&ft_philos_routine,
				(void *)&prg->philo[i]))
			return (printf("Error creating threads."));
		usleep(100);
	}
	ft_is_dead(prg->philo);
	ft_philo_deleter(prg);
	free(thr);
	return (0);
}