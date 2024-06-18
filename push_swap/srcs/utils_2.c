/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 04:42:07 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 08:46:52 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split_arg(char **split_arg)
{
	char	**temp;

	temp = split_arg;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(split_arg);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*v;

	v = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		v[i] = c;
		i++;
	}
	b = v;
	return (v);
}
