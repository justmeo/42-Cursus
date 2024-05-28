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

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>



//split

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && size > 1)
	{
		*dest++ = *src++;
		size--;
		i++;
	}
	if (size > 0)
		*dest = '\0';
	while (*src++)
		i++;
	return (i);
}

static size_t	size(const char *str, char x)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str == x)
		{
			str++;
		}
		else
		{
			i++;
			while (*str != x)
			{
				str++;
				if (*str == '\0')
					return (i);
			}
		}
	}
	return (i);
}

static size_t	sizme(const char *str, char x)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str == x)
		{
			str++;
		}
		else
		{
			i++;
			while (*str != x)
			{
				str++;
				i++;
				if (*str == '\0')
					return (i);
			}
		}
	}
	return (i);
}

static char	**copie(char const *s, char c)
{
	char	**me;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	me = (char **)malloc(sizeof(char *) * (size(s, c) + 1));
	if (!me)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > k)
		{
			me[j] = (char *)malloc(sizeof(char) * (sizme(s, c) + 1));
			ft_strlcpy(me[j++], s + k, i - k + 1);
		}
	}
	me[j] = NULL;
	return (me);
}

char	**ft_split(char const *s, char c)
{
	char	**me;

	if (!s)
		return (NULL);
	me = copie(s, c);
	if (!me)
		return (NULL);
	return (me);
}

//split 
// qsort
void ft_swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
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

void ft_qsort(int arr[], int low, int high) 
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

int	is_duplicate(int *arr, int len, int num)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (arr[i] == num)
            return (1);
    }
    return (0);
}


int	main(int ac, char **av)
{
    int *arr;
    int i;
    int j;
    int num;
    char **split_arg;
    int k;

    arr = (int *)malloc(sizeof(int) * (ac - 1));
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
            num = atoi(split_arg[k]);
            if (is_duplicate(arr, j, num))
            {
                printf("Error: Duplicate number %d\n", num);
                free(arr);
                return (1);
            }
            arr[j++] = num;
            k++;
        }
        i++;
    }
    // sort the array
    ft_qsort(arr, 0, j - 1);
    // print the sorted array
    for (i = 0; i < j; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return (0);
}