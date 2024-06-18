/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 04:42:16 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 09:17:22 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long long	handle_overflow(t_atoll *atoll)
{
	if (atoll->sign == 1 && (atoll->result < atoll->prev_result || atoll->result
			/ 10 != atoll->prev_result))
		return (atoll->result);
	if (atoll->sign == -1 && (atoll->result > atoll->prev_result
			|| atoll->result / 10 != atoll->prev_result))
		return (atoll->result);
	return (0);
}

void	sign_atoll(const char *str, int i)
{
	t_atoll	atoll;

	if (str[i] == '-')
	{
		atoll.sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
}

long long int	ft_atoll(const char *str, int *error)
{
	t_atoll	atoll;
	int		i;

	atoll.sign = 1;
	atoll.result = 0;
	atoll.prev_result = 0;
	i = 0;
	sign_atoll(str, i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoll.prev_result = atoll.result;
		atoll.result = atoll.result * 10 + atoll.sign * (str[i] - '0');
		if (handle_overflow(&atoll) || INT_MAX < atoll.result
			|| INT_MIN > atoll.result)
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	*error = 0;
	return (atoll.result);
}
