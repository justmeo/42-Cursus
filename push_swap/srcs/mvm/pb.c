/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:06:05 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 13:04:23 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pb(long long int *array, int *size, long long int *temp_array,
		int *temp_size)
{
	int	i;

	i = 0;
	temp_array[*temp_size] = array[0];
	while (i < *size - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
	(*size)--;
	(*temp_size)++;
	ft_printf("pb\n");
}
