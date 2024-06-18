/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:06:10 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 07:36:58 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(long long int *array, int *size, long long int *temp_array,
		int *temp_size)
{
	int	i;

	i = *size;
	while (i > 0)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[0] = temp_array[*temp_size - 1];
	(*size)++;
	(*temp_size)--;
	ft_printf("pa\n");
}
