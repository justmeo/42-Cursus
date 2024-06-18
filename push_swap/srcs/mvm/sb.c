/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:04:44 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 07:18:41 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sb(long long int *b, int len_b, int i)
{
	long long int	temp;

	if (len_b > 1)
	{
		temp = b[i];
		b[i] = b[i + 1];
		b[i + 1] = temp;
		ft_printf("sb\n");
	}
}
