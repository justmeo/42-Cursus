/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:50:40 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/16 18:30:32 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	u;
	size_t	i;
	char	*me;

	i = 0;
	u = count * size;
	me = (char *)malloc(u);
	if (!me)
		return (NULL);
	while (i < u)
	{
		me[i] = 0;
		i++;
	}
	return (me);
}
