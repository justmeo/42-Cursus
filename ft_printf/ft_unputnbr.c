/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:48:12 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/13 13:47:48 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unputnbr(unsigned int n)
{
	if (n > 9)
	{
		ft_unputnbr(n / 10);
		ft_unputnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
