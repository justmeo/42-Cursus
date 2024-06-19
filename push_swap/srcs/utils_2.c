/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 04:42:07 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/20 02:19:05 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split_arg(char **split_arg)
{
	char	**temp;

	temp = split_arg;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(split_arg);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*v;

	v = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		v[i] = c;
		i++;
	}
	b = v;
	return (v);
}

void	help_help(long long int *a, int k, int min_index, int j)
{
	long long int	temp;

	temp = a[min_index];
	j = min_index;
	while (j > 0)
	{
		if (min_index > 3)
		{
			rra(a, k);
			break ;
		}
		ra(a, k);
		j--;
	}
	a[0] = temp;
}

void	help_five_num(long long int *a, int k, int a_size)
{
	int	min_index;
	int	j;

	min_index = 0;
	j = 1;
	while (j < a_size)
	{
		if (a[j] < a[min_index])
			min_index = j;
		j++;
	}
	if (min_index != 0)
	{
		help_help(a, k, min_index, j);
	}
}

int	check_per(long long *arr, int ac, char **av)
{
	int	i;
	int	me;
	int	j;

	j = 1;
	me = sizep(ac, av);
	i = 0;
	while (j < me)
	{
		if (arr[i] < arr[j])
		{
			i++;
			j++;
		}
		else
		{
			return (false);
		}
	}
	free(arr);
	return (true);
}
