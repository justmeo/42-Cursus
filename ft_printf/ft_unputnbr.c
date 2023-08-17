/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:48:12 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/15 10:54:54 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	me(unsigned int me)
{
	int	you;

	you = 0;
	if (me == 0)
		return (1);
	while (me > 0)
	{
		me /= 10;
		you++;
	}
	return (you);
}

int	ft_unputnbr(unsigned int n)
{
	if (n > 9)
	{
		ft_unputnbr(n / 10);
		ft_unputnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (me(n));
}
