/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 04:42:07 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/13 17:49:52 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/push_swap.h"

void sa(long long int *a, int len_a, int i)
{
    long long int temp;
    if (len_a > 1)
    {
        temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
        ft_printf("sa\n");
    }
}

void sb(long long int *b, int len_b , int i)
{
    long long int temp;
    if (len_b > 1)
    {
        temp = b[i];
        b[i] = b[i + 1];
        b[i + 1] = temp;
        ft_printf("sb\n");
    }
}

void ss(long long int *a, int len_a, long long int *b, int len_b)
{
    sa(a, len_a , 0);
    sb(b, len_b , 0);
    ft_printf("ss\n");
}

void rb(long long int *b, int len_b)
{
    long long int temp;
    if (len_b > 0)
    {
        temp = b[0];
        memmove(b, b + 1, sizeof(int) * (len_b - 1));
        b[len_b - 1] = temp;
        ft_printf("rb\n");
    }
}

void ra(long long int *array, int size) {
    long long int temp = array[0];
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = temp;
        ft_printf("ra\n");

}

void rr(long long int *a, int len_a, long long int *b, int len_b)
{
    ra(a, len_a);
    rb(b, len_b);
    ft_printf("rr\n");
}

void rra(long long int *a, int len_a)
{
    long long int temp;
    if (len_a > 0)
    {
        temp = a[len_a - 1];
        memmove(a + 1, a, sizeof(long long int) * (len_a - 1));
        a[0] = temp;
        ft_printf("rra\n");
    }
}

void rrb(long long int *b, int len_b)
{
    long long int temp;
    if (len_b > 0)
    {
        temp = b[len_b - 1];
        memmove(b + 1, b, sizeof(long long int) * (len_b - 1));
        b[0] = temp;
        ft_printf("rrb\n");
    }
}

void rrr(long long int *a, int len_a, long long int *b, int len_b)
{
    rra(a, len_a);
    rrb(b, len_b);
    ft_printf("rrr\n");
}



void pb(long long int *array, int *size, long long int *temp_array, int *temp_size) {
    temp_array[*temp_size] = array[0];
    for (int i = 0; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }
    (*size)--;
    (*temp_size)++;
        ft_printf("pb\n");

}

void pa(long long int *array, int *size, long long int *temp_array, int *temp_size) {
    for (int i = *size; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = temp_array[*temp_size - 1];
    (*size)++;
    (*temp_size)--;
    ft_printf("pa\n");
}

// void pa(long long int *a, int *len_a, long long int *b, int *len_b) {
//     if (*len_b > 0) {
//         a[*len_a] = b[0];
//         (*len_a)++;
//         memmove(b, b + 1, sizeof(int) * (*len_b - 1));
//         (*len_b)--;
//         printf("pa\n");
//     }
// }

// void pb(long long int *a, int *len_a, long long int *b, int *len_b) {
//     if (*len_a > 0) {
//         b[*len_b] = a[0];
//         (*len_b)++;
//         memmove(a, a + 1, sizeof(int) * (*len_a - 1));
//         (*len_a)--;
//         printf("pb\n");
//     }
// }

// void ra(long long int *a, int len_a)
// {
//     long long int temp;
//     if (len_a > 0)
//     {
//         temp = a[0];
//         memmove(a, a + 1, sizeof(long long int) * (len_a - 1));
//         a[len_a - 1] = temp;
//         printf("ra\n");
//     }
// }
