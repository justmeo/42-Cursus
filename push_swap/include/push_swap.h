/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:59:30 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/28 15:00:40 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

//  libraries 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

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


// Define any structs here




// Declare function prototypes here

#endif // PUSH_SWAP_H
