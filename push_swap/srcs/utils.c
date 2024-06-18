/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 06:55:22 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 08:55:54 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(long long int *arr, int len, long long int num)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	func1(long long int *gg, int *i)
{
	i[0] = 0;
	while (i[0] < i[2])
	{
		gg[i[0]] = 0;
		i[0]++;
	}
}

void	func2(long long int *arr_copy, long long int temp, int *i)
{
	i[0] = 0;
	while (i[0] < i[2] - 1)
	{
		i[1] = i[0] + 1;
		while (i[1] < i[2])
		{
			if (arr_copy[i[0]] > arr_copy[i[1]])
			{
				temp = arr_copy[i[0]];
				arr_copy[i[0]] = arr_copy[i[1]];
				arr_copy[i[1]] = temp;
			}
			i[1]++;
		}
		i[0]++;
	}
}

void	func3(long long int *arr_copy, long long int *gg, long long int *arr,
		int *i)
{
	i[0] = 0;
	while (i[0] < i[2])
	{
		i[1] = 0;
		while (i[1] < i[2])
		{
			if (arr[i[1]] == arr_copy[i[0]])
			{
				gg[i[1]] = i[0] + 1;
				break ;
			}
			i[1]++;
		}
		i[0]++;
	}
}
