/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:20:40 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/16 09:58:01 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_up(unsigned long n)
{
	int	i;

	i = them(n);
	if (n > 15)
	{
		ft_puthex_up(n / 16);
		ft_puthex_up(n % 16);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
		ft_putchar(n + 55);
	return (i);
}
