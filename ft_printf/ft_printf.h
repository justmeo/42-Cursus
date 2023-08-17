/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:08:30 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/16 09:57:54 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_puthex_low(unsigned long n);
int	ft_puthex_up(unsigned long n);
int	ft_putnbr(int n);
int	ft_putoint(unsigned long n);
int	ft_putstr(char *s);
int	ft_unputnbr(unsigned int n);
int	them(unsigned long me);
int	ft_printf(const char *me, ...);

#endif
