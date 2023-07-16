/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:23:41 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/16 18:33:08 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	me;
	int	sign;

	sign = 1;
	me = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0' && *str <= '9'))
		me = me * 10 + (*str++ - '0');
	return (me * sign);
}

// int	main(void)
// {
// 	char	str[800] = "-18446744073709551615";

// 	__LONG_MAX__;
// 	UINT64_MAX;

// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// }
