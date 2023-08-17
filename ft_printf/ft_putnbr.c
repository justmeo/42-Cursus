/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:12:09 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/15 13:06:45 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	me2(int me)
{
	int	you;

	you = 0;
	if (me == 0)
		return (1);
	if (me < 0)
	{
		me *= -1;
		you++;
	}
	while (me > 0)
	{
		me /= 10;
		you++;
	}
	return (you);
}

int	ft_putnbr(int n)
{
	bool	a;
	int		she;

	she = me2(n);
	a = false;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return (11);
	}
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		a = true;
	}
	if (a == true && n != -2147483648)
		write(1, "-", 1);
	if (n > 9 && n != -2147483648)
		ft_putnbr(n / 10);
	if (n != -2147483648)
		ft_putchar(n % 10 + '0');
	return (she);
}
