/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:01:58 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/09/24 14:53:23 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philos_routine(void *p) 
{
    t_philo *philo;

    philo = (t_philo *)p;
    while (!philo->args->dead && philo->args->end_ate < philo->args->n_philos) {
        pthread_mutex_lock(&philo->forks_locker[(philo->id) - 1]);  // Take left fork
        ft_print(philo, "has taken a fork", 0);
        pthread_mutex_lock(&philo->forks_locker[(philo->id) % philo->args->n_philos]); // Take right fork
        ft_print(philo, "has taken a fork", 0);
        ft_print(philo, "is eating", 0);     // Start eating
        philo->last_meal = ft_actual_time();
        ft_time_usleep(philo->args->timetoeat);  // Sleep while eating
        pthread_mutex_unlock(&philo->forks_locker[(philo->id) % philo->args->n_philos]); // Release right fork
        pthread_mutex_unlock(&philo->forks_locker[(philo->id) - 1]);   // Release left fork
        if (++philo->ate == philo->args->n_timeeat)  // Check if eating requirement met
            philo->args->end_ate++;
        if (!philo->args->dead) {
            ft_print(philo, "is sleeping", 0);
            ft_time_usleep(philo->args->timetosleep);  // Sleep
            ft_print(philo, "is thinking", 0);   // Think
        }
    }
}

unsigned long ft_actual_time(void) 
{
    struct timeval time;
    unsigned long ret;

    gettimeofday(&time, NULL);
    ret = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
    return (ret);
}

unsigned long ft_elapse_time(t_philo *philos) 
{
    unsigned long ret;

    ret = ft_actual_time() - philos->init_time;
    return (ret);
}

void ft_print(t_philo *philo, char *text, int dead) 
{
    pthread_mutex_lock(philo->print_locker);
    if (dead != 2)
        printf("%lums	%d	%s.\n", ft_elapse_time(philo), philo->id, text);
    if (dead == 1 || dead == 2)
        return ;
    pthread_mutex_unlock(philo->print_locker);
}

int ft_atoi(char *str) 
{
    long n;
    int s;

    s = 1;
    n = 0;
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')
        str++;
    if (*str == '-' || *str == '+') {
        if (*str == '-')
            s = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        n = (n * 10) + (*str - 48);
        str++;
    }
    if (n > INT32_MAX)
        return (0);
    return (s * (int)n);
}
