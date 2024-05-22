/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:57:13 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/22 12:25:03 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	send_bit(int pid, char c, int bit)
{
	int	signo;

	if (c & (1 << bit))
		signo = SIGUSR2;
	else
		signo = SIGUSR1;
	kill(pid, signo);
	usleep(100);
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
		return (1);
	pid = atoi(argv[1]);
	send_string(pid, argv[2]);
	return (0);
}
