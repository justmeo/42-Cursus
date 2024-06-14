/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:59:30 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/13 17:10:00 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

//  libraries 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

//  structs

typedef struct s_atoll
{
    long long result;
    long long prev_result;
    int sign;
}               t_atoll;

// Usful functions

long long int ft_atoll(const char *str, int *error);
char	**ft_split(char const *s, char c);
void sa(long long int *a, int len_a,int i);
void pa(long long int *a, int *len_a, long long int *b, int *len_b);
void pb(long long int *a, int *len_a, long long int *b, int *len_b);
void ra(long long int *a, int len_a);
void two_digit(long long int *me);
void sort_three_digits(long long int *me) ;
void rb(long long int *b, int len_b);
void rra(long long int *a, int len_a);
void rrb(long long int *b, int len_b);
void radix_sort(long long int *array, int size);




// Define any structs here




// Declare function prototypes here

#endif // PUSH_SWAP_H
