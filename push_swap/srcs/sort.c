/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 04:42:02 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/14 13:58:28 by ymrabeti         ###   ########.fr       */
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
	if (me[0] > me[1] && me[0] > me[2] && me[1] < me[2])
		ra(me, 3);
	else if (me[0] > me[1] && me[1] < me[2])
		sa(me, 2, 0);
	else if (me[0] < me[1] && me[0] > me[2])
		rra(me, 3);
	else if (me[0] < me[1] && me[1] > me[2])
		sa(me, 2, 1);
	else if (me[0] > me[1] && me[1] > me[2])
	{
		ra(me, 3);
		sa(me, 2, 0);
	}
}

int	get_max_bits(long long int *array, int size)
{
	long long int	max_value;
	int				bits;

	max_value = LLONG_MIN;
	bits = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	while (max_value)
	{
		max_value >>= 1;
		bits++;
	}
	return (bits);
}

// void	radix_sort(long long int *array, int size)
// {
// 	int				max_bits;
// 	long long int	*temp_array;
// 	int				j = 0;;
// 	int len;
// 	int i = -1;

// 	max_bits = get_max_bits(array, size);
// 	temp_array = malloc(size * sizeof(long long int));
// 	if (temp_array == NULL)
// 	{
// 		// Handle memory allocation failure
// 		return ;
// 	}
//     while (++i < max_bits)
// 	{
// 		len = size;
// 		while (len-- > 0)
// 		{
// 			if (((array[j] >> i) & 1) == 1)
// 				ra(array,size);
// 			else
// 				pb(array,&size, temp_array,&size);
// 		}
// 		while (*temp_array)
// 			pa(array,&size, temp_array,&size);

// 	}
// 	free(temp_array);
// }


void radix_sort(long long int *array, int size)
{
    int max_bits;
    long long int *temp_array;
    int j = 0;
    int len;
    int i = -1;

    max_bits = get_max_bits(array, size);
    temp_array = malloc(size * sizeof(long long int));
    if (temp_array == NULL)
    {
        // Handle memory allocation failure
        return;
    }
    while (++i < max_bits)
    {
        len = size;
        while (len-- > 0)
        {
            if (((array[j] >> i) & 1) == 1)
                ra(array, size);
            else
                pb(array, &size, temp_array, &size);
        }
        // Copy elements back from temp_array to array
        while (size > 0)
            pa(array, &size, temp_array, &size);
    }
    free(temp_array);
}
