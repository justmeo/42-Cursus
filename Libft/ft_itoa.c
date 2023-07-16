/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:29:48 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/16 09:35:40 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		me;
	int		len;
	int		sign;
	char	*str;
	int		i;

	me = n;
	len = 0;
	sign = 0;
	if (me < 0)
	{
		sign = 1;
		me *= -1;
		len++;
	}
	while (me > 0)
	{
		me /= 10;
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	me = n;
	str[len] = '\0';
	if (me < 0)
	{
		me *= -1;
		str[0] = '-';
	}
	if (me == 0)
		str[0] = 0;
	else
	{
		i = len - 1;
		while (me > 0)
		{
			str[i] = me % 10 + '0';
			me /= 10;
			i--;
		}
	}
	return (str);
}

// int main()
// {
//     printf("%s",ft_itoa(   -1235));
// }