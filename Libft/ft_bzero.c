/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:35:03 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/04 14:45:46 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int i;
	unsigned char *v;

	v = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		v[i] = 0;
		i++;
	}
	s = v;
	return (v);
}
