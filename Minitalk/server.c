/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:57:18 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/28 14:55:47 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	handle_signal(int sig)
{
	static char	x;
	static int	bits;

	x = (x << 1);
	if (sig == SIGUSR2)
		x = x | 1;
	bits++;
	if (bits == 8)
	{
		if (x == '\0')
			write(1, "\n", 1);
		else
			write(1, &x, 1);
		bits = 0;
		x = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		return (0);
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
