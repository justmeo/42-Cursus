/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:59:33 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/28 16:30:22 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>
#include <stdio.h>


void ft_swap(long long int* a, long long int* b) 
{ 
    long long int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(long long int arr[], int low, int high) 
{ 
    long long int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++; 
            ft_swap(&arr[i], &arr[j]); 
        } 
    } 
    ft_swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void ft_qsort(long long int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 

        ft_qsort(arr, low, pi - 1); 
        ft_qsort(arr, pi + 1, high); 
    } 
} 
// till here



int	is_number(char *str)
{
    int i = 0;
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

int	is_duplicate(long long int *arr, int len, long long int num) // change arr and num to long long int
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (arr[i] == num)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    long long int *arr;
    long long int num;
    int i;
    int j;
    char **split_arg;
    int k;
	int error;

    arr = (long long int *)malloc(sizeof(long long int) * (ac - 1));
    if (!arr)
        return (1);
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
                printf("Error: Invalid number %s\n", split_arg[k]);
                free(arr);
                return (1);
            }
            num = ft_atoll(split_arg[k], &error);
            if (error)
            {
                printf("Error: Number out of range %s\n", split_arg[k]);
            free(arr);
            return (1);
        }
            if (is_duplicate(arr, j, num))
            {
                printf("Error: Duplicate number %lld\n", num);
                free(arr);
                return (1);
            }
            arr[j++] = num;
            k++;
        }
        i++;
    }
    ft_qsort(arr, 0, j - 1);
    for (i = 0; i < j; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    free(arr);
    return (0);
}
