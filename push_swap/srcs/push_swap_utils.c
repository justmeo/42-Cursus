/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 06:57:10 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 07:41:13 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

char	*free_arr(char **split_arg, long long int *arr)
{
	free(arr);
	free_split_arg(split_arg);
	return (NULL);
}

char	*error_inv(char **split_arg, long long int *arr, int k)
{
	ft_printf("Error: Invalid number %s\n", split_arg[k]);
	return (free_arr(split_arg, arr));
}

char	*error_range(char **split_arg, long long int *arr, int k)
{
	ft_printf("Error: Number out of range %s\n", split_arg[k]);
	return (free_arr(split_arg, arr));
}

char	*error_dup(char **split_arg, long long int *arr)
{
	ft_printf("Error: Duplicate number \n");
	return (free_arr(split_arg, arr));
}

char	*error_loop(char **split_arg, long long int *arr, int *i, int *error)
{
	long long int	num;

	i[2] = 0;
	while (split_arg[i[2]])
	{
		if (!is_number(split_arg[i[2]]))
			return (error_inv(split_arg, arr, i[2]));
		num = ft_atoll(split_arg[i[2]], error);
		if (*error)
			return (error_range(split_arg, arr, i[2]));
		if (is_duplicate(arr, i[1], num))
			return (error_dup(split_arg, arr));
		arr[i[1]++] = num;
		i[2]++;
	}
	return ((void *)1);
}
