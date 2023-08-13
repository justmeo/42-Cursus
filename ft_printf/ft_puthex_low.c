/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:17:46 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/13 10:18:16 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_low(unsigned int n)
{
	if (n > 15)
	{
		ft_puthex_low(n / 16);
		ft_puthex_low(n % 16);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
		ft_putchar(n + 87);
}
