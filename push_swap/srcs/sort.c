/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 04:42:02 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/18 13:04:22 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>
#include <math.h>

void	two_digit(long long int *me)
{
	if (me[1] < me[0])
		sa(me, 2, 0);
}

void	sort_three_digits(long long int *me)
{
	int	i;

	i = 3;
	if (me[0] > me[1] && me[0] > me[2] && me[1] < me[2])
		ra(me, i);
	else if (me[0] > me[1] && me[1] < me[2])
		sa(me, 2, 0);
	else if (me[0] < me[1] && me[0] > me[2])
		rra(me, 3);
	else if (me[0] < me[1] && me[1] > me[2])
		sa(me, 2, 1);
	else if (me[0] > me[1] && me[1] > me[2])
	{
		ra(me, i);
		sa(me, 2, 0);
	}
}

void sort_five_numbers(long long int *a)
{
    long long int b[2];
    int a_size = 5;
    int b_size = 0;

    // Push the smallest number to b
    for (int i = 0; i < 2; i++) {
        int min_index = 0;
        for (int j = 1; j < a_size; j++) {
            if (a[j] < a[min_index])
                min_index = j;
        }
        // Move the smallest element to the front
        if (min_index != 0) {
            long long int temp = a[min_index];
            for (int j = min_index; j > 0; j--)
                a[j] = a[j - 1];
            a[0] = temp;
        }
        pb(a, &a_size, b, &b_size);
    }

    // Sort the remaining three numbers
    sort_three_digits(a);

    // Sort the two numbers in b
    two_digit(b);

    // Push the sorted numbers back to a
    pa(a, &a_size, b, &b_size);
    pa(a, &a_size, b, &b_size);
}

int	get_max_bits(long long int *array, int size)
{
	long long int	max_value;
	int				bits;
	int				i;

	i = 0;
	max_value = LLONG_MIN;
	bits = 0;
	while (i < size)
	{
		if (array[i] > max_value)
			max_value = array[i];
		i++;
	}
	while (max_value)
	{
		max_value >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(long long int *array_a, int size_a)
{
	int				max_bits;
	long long int	*array_b;
	int				i[3];

	i[0] = 0;
	max_bits = get_max_bits(array_a, size_a);
	array_b = malloc(size_a * sizeof(long long int));
	if (array_b == NULL)
		return ;
	i[2] = 0;
	while (i[0] < max_bits)
	{
		i[1] = size_a;
		while (i[1]-- > 0)
		{
			if ((((*array_a) >> i[0]) & 1) == 1)
				ra(array_a, size_a);
			else
				pb(array_a, &size_a, array_b, &i[2]);
		}
		while (i[2] > 0)
			pa(array_a, &size_a, array_b, &i[2]);
		i[0]++;
	}
	free(array_b);
}
