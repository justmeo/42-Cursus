/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:06:11 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 07:37:09 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rb(long long int *b, int len_b)
{
	long long int	temp;

	if (len_b > 0)
	{
		temp = b[0];
		ft_memmove(b, b + 1, sizeof(int) * (len_b - 1));
		b[len_b - 1] = temp;
		ft_printf("rb\n");
	}
}
