/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:12:12 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/16 10:26:05 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(char *str, int i, va_list ap)
{
	if (str[i] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (str[i] == 'u')
		return (ft_unputnbr(va_arg(ap, unsigned int)));
	else if (str[i] == 'x')
		return (ft_puthex_low(va_arg(ap, unsigned int)));
	else if (str[i] == 'X')
		return (ft_puthex_up(va_arg(ap, unsigned int)));
	else if (str[i] == 'p')
		return (ft_putoint(va_arg(ap, unsigned long)));
	else if (str[i] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *me, ...)
{
	va_list	ap;
	int		i;
	int		he;

	i = 0;
	he = 0;
	va_start(ap, me);
	while (me[i])
	{
		if (me[i] == '%')
			he += check((char *)me, ++i, ap);
		else
			he += ft_putchar(me[i]);
		i++;
	}
	va_end(ap);
	return (he);
}

// int	main(void)
// {
// 	ft_printf("Hello %s\n", "world");
// 	ft_printf("Hello %c\n", 'c');
// 	ft_printf("Hello %d\n", 42);
// 	ft_printf("Hello %i\n", 42);
// 	ft_printf("Hello %u\n", 42);
// 	ft_printf("Hello %x\n", 42);
// 	ft_printf("Hello %X\n", 42);
// 	ft_printf("Hello %p\n", 42);
// 	ft_printf("Hello %%\n");
// 	return (0);
// }
