/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:03:57 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 07:18:38 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(long long int *a, int len_a, int i)
{
	long long int	temp;

	if (len_a > 1)
	{
		temp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = temp;
		ft_printf("sa\n");
	}
}
