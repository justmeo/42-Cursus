/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:33:30 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/16 14:43:01 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	bool	a;

	a = false;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		a = true;
	}
	if (a == true && n != -2147483648)
		write(fd, "-", 1);
	if (n > 9 && n != -2147483648)
		ft_putnbr_fd(n / 10, fd);
	if (n != -2147483648)
		ft_putchar_fd(n % 10 + '0', fd);
}
