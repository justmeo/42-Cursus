/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:09:44 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 07:21:37 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (s < d)
	{
		s += n;
		d += n;
		while (n--)
			*--d = *--s;
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}

void	rra(long long int *a, int len_a)
{
	long long int	temp;

	if (len_a > 0)
	{
		temp = a[len_a - 1];
		ft_memmove(a + 1, a, sizeof(long long int) * (len_a - 1));
		a[0] = temp;
		ft_printf("rra\n");
	}
}
