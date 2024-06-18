/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:06:12 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 07:37:06 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(long long int *array, int size)
{
	long long int	temp;
	int				i;

	i = 0;
	temp = array[0];
	while (i < size - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[size - 1] = temp;
	ft_printf("ra\n");
}
