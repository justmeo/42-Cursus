/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 04:42:16 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/20 02:24:28 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	handle_space(char **av)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (av[1][i])
	{
		if (av[1][i] != 32)
			flag = 1;
		i++;
	}
	if (flag == 0)
		return (1);
	return (0);
}

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

int	sign_atoll(const char *str)
{
	if (str[0] == '-')
		return (-1);
	else if (str[0] == '+')
		return (1);
	return (1);
}

long long int	ft_atoll(const char *str, int *error)
{
	t_atoll	atoll;
	int		i;

	i = 0;
	atoll.sign = sign_atoll(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	atoll.result = 0;
	atoll.prev_result = 0;
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
