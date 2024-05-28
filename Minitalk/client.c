/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:57:13 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/28 14:55:44 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	long	me;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	me = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
		me = me * 10 + (str[i++] - '0');
	if (str[i])
		return (-1);
	return (me * sign);
}

void	send_bit(int pid, char c, int bit)
{
	int	sig;

	if (c & (1 << bit))
		sig = SIGUSR2;
	else
		sig = SIGUSR1;
	kill(pid, sig);
	usleep(150);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit(pid, c, i);
		i--;
	}
}

void	send_string(int pid, char *str)
{
	while (*str)
		send_char(pid, *str++);
	send_char(pid, *str);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (0);
	send_string(pid, argv[2]);
	return (0);
}
