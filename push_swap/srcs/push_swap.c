/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:59:33 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/20 02:24:41 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	sizep(int ac, char **av)
{
	char	**split_arg;
	int		k;
	int		i;
	int		x;

	i = 1;
	x = 0;
	while (i < ac)
	{
		split_arg = ft_split(av[i], ' ');
		k = 0;
		while (split_arg[k])
		{
			k++;
			x++;
		}
		i++;
		free_split_arg(split_arg);
	}
	return (x);
}

long long int	*parse_arguments(int ac, char **av, int *error)
{
	long long int	*arr;
	int				i[3];
	char			**split_arg;

	arr = (long long int *)malloc(sizeof(long long int) * (sizep(ac, av)));
	if (!arr)
		return (NULL);
	i[0] = 1;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < ac)
	{
		split_arg = ft_split(av[i[0]], ' ');
		if (!error_loop(split_arg, arr, i, error))
			return (NULL);
		free_split_arg(split_arg);
		i[0]++;
	}
	return (arr);
}

long long int	*kk(long long int *arr, int ac, char **av)
{
	int				i[3];
	long long int	*gg;
	long long int	*arr_copy;
	long long int	temp;

	i[0] = 0;
	i[1] = 0;
	temp = 0;
	i[2] = sizep(ac, av);
	gg = malloc(sizeof(long long int) * i[2]);
	arr_copy = malloc(sizeof(long long int) * i[2]);
	while (i[0] < i[2])
	{
		arr_copy[i[0]] = arr[i[0]];
		i[0]++;
	}
	func1(gg, i);
	func2(arr_copy, temp, i);
	func3(arr_copy, gg, arr, i);
	free(arr_copy);
	return (gg);
}

void	sort_numbers(long long int *arr, int ac, char **av)
{
	if (sizep(ac, av) == 2)
		two_digit(arr);
	else if (sizep(ac, av) == 3)
		sort_three_digits(arr);
	else if (sizep(ac, av) == 5)
		sort_five_numbers(arr);
	else if (sizep(ac, av) > 5 || sizep(ac, av) == 4)
		radix_sort(arr, sizep(ac, av));
	free(arr);
}

int	main(int ac, char **av)
{
	long long int	*arr;
	long long int	*tmp;
	int				error;

	if (ac == 1)
		return (0);
	if (handle_space(av) == 1)
	{
		ft_printf("Error: Invalid number\n");
		return (0);
	}
	tmp = parse_arguments(ac, av, &error);
	if (!tmp)
		return (1);
	arr = kk(tmp, ac, av);
	if (!arr)
		return (1);
	if (check_per(arr, ac, av) == 1)
	{
		free(tmp);
		return (0);
	}
	sort_numbers(arr, ac, av);
	free(tmp);
	return (0);
}
