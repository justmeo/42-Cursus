/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:17:46 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/16 09:57:37 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	them(unsigned long me)
{
	int	you;

	you = 0;
	if (me == 0)
		return (1);
	while (me > 0)
	{
		me /= 16;
		you++;
	}
	return (you);
}

int	ft_puthex_low(unsigned long n)
{
	int	i;

	i = them(n);
	if (n > 15)
	{
		ft_puthex_low(n / 16);
		ft_puthex_low(n % 16);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
		ft_putchar(n + 87);
	return (i);
}
