/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:29:48 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/18 11:48:30 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(long x)
{
	size_t	len;

	len = 0;
	if (x < 0)
	{
		x *= -1;
		len++;
	}
	if (x == 0)
		return (1);
	while (x > 0)
	{
		x /= 10;
		len++;
	}
	return (len);
}

static char	*calcul(char *str, long x)
{
	int	i;

	i = 0;
	if (x < 0)
	{
		x *= -1;
		str[0] = '-';
		i = ft_size(x);
	}
	else
		i = ft_size(x) - 1;
	if (x == 0)
		str[0] = '0';
	while (x > 0)
	{
		str[i] = x % 10 + '0';
		x /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	me;

	me = n;
	str = (char *)malloc((ft_size(me) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[ft_size(me)] = '\0';
	return (calcul(str, me));
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(-2147483648));
// }