/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:59:33 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/13 17:00:57 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>
#include <stdio.h>



void free_split_arg(char **split_arg)
{
    char **temp = split_arg;
    while (*temp)
    {
        free(*temp);
        temp++;
    }
    free(split_arg);
}

long long int *parse_arguments(int ac, char **av, int *error)
{
    long long int *arr;
    long long int num;
    int i;
    int j;
    char **split_arg;
    int k;

  arr = (long long int *)malloc(sizeof(long long int) * (ac - 1));
if (!arr)
    return NULL;
i = 1;
j = 0;
while (i < ac)
{
    split_arg = ft_split(av[i], ' ');
    k = 0;
    while (split_arg[k])
    {
        if (!is_number(split_arg[k]))
        {
            ft_printf("Error: Invalid number %s\n", split_arg[k]);
            free(arr);
            free_split_arg(split_arg); // free split_arg before returning
            return NULL;
        }
        num = ft_atoll(split_arg[k], error);
        if (*error)
        {
            ft_printf("Error: Number out of range %s\n", split_arg[k]);
            free(arr);
            free_split_arg(split_arg); // free split_arg before returning
            return NULL;
        }
        if (is_duplicate(arr, j, num))
        {
            ft_printf("Error: Duplicate number \n");
            free(arr);
            free_split_arg(split_arg); // free split_arg before returning
            return NULL;
        }
        arr[j++] = num;
        k++;
    }
    free_split_arg(split_arg); // free split_arg after using it
    i++;
}
return arr;
}

void sort_numbers(long long int *arr, int ac)
{
    // int i =0;
    if(ac == 3)
        two_digit(arr);
    else if(ac == 4)
        sort_three_digits(arr);
    else if(ac > 4)
        radix_sort(arr,ac - 1);
    // for (i = 0; i < ac - 1; i++)
    // {
    //     ft_printf("%lld ", arr[i]);
    // }
    // ft_printf("\n");
    free(arr);
}

int main(int ac, char **av)
{
    long long int *arr;
    int error;

    if(ac == 1)
    {
        ft_printf("Error: Invalid input\n");
        return 0;
    }
    arr = parse_arguments(ac, av, &error);
    if (!arr)
        return 1;
    sort_numbers(arr, ac);
    
    return 0;
}
