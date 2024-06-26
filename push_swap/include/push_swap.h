/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:59:30 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/06/20 02:34:19 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_atoll
{
	long long int	result;
	long long int	prev_result;
	int				sign;
}					t_atoll;

long long int		ft_atoll(const char *str, int *error);
int					is_number(char *str);
int					is_duplicate(long long int *arr, int len,
						long long int num);
char				**ft_split(char const *s, char c);
void				two_digit(long long int *me);
void				sort_three_digits(long long int *me);
void				radix_sort(long long int *array_a, int size_a);
void				sort_five_numbers(long long int *a);
int					check_per(long long *arr, int ac, char **av);
int					sizep(int ac, char **av);
void				help_five_num(long long int *a, int k, int a_size);
int					handle_space(char **av);

void				*ft_memmove(void *dest, const void *src, size_t n);
void				sa(long long int *a, int len_a, int i);
void				pa(long long int *a, int *len_a, long long int *b,
						int *len_b);
void				pb(long long int *a, int *len_a, long long int *b,
						int *len_b);
void				ra(long long int *a, int len_a);
void				rb(long long int *b, int len_b);
void				rra(long long int *a, int len_a);

void				*ft_memset(void *b, int c, size_t len);
char				*free_arr(char **split_arg, long long int *arr);
char				*error_inv(char **split_arg, long long int *arr, int k);
char				*error_range(char **split_arg, long long int *arr, int k);
char				*error_dup(char **split_arg, long long int *arr);
char				*error_loop(char **split_arg, long long int *arr, int *i,
						int *error);
void				func1(long long int *gg, int *i);
void				func2(long long int *arr_copy, long long int temp, int *i);
void				func3(long long int *arr_copy, long long int *gg,
						long long int *arr, int *i);
void				free_split_arg(char **split_arg);

#endif
