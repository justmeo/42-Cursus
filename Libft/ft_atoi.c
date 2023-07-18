/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:23:41 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/18 08:15:04 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	first(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_sign(const char *str)
{
	int	i;
	int	j;

	j = first(str);
	i = 1;
	if (str[j] == '-')
		i = -1;
	return (i);
}

int	ft_atoi(const char *str)
{
	long	me;
	int		i;

	i = first(str);
	me = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
		me = me * 10 + (str[i++] - '0');
	return (me * ft_sign(str));
}

// int	main(void)
// {
// 	char	str[50] = "87945127894518528549859845";

// 	__LONG_MAX__;
// 	UINT64_MAX;
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// }
