

#include "../include/push_swap.h"

// long long int *allocate_array(int ac)
// {
//     long long int *arr = (long long int *)malloc(sizeof(long long int) * (ac - 1));
//     return arr;
// }

// void handle_error(long long int *arr, char **split_arg)
// {
//     free(arr);
//     free_split_arg(split_arg);
// }

// long long int *parse_split_arg(char **split_arg, long long int *arr, int *j, int *error)
// {
//     int k = 0;
//     long long int num;
//     while (split_arg[k])
//     {
//         if (!is_number(split_arg[k]))
//         {
//             ft_printf("Error: Invalid number %s\n", split_arg[k]);
//             handle_error(arr, split_arg);
//             return NULL;
//         }
//         num = ft_atoll(split_arg[k], error);
//         if (*error)
//         {
//             ft_printf("Error: Number out of range %s\n", split_arg[k]);
//             handle_error(arr, split_arg);
//             return NULL;
//         }
//         arr[(*j)++] = num;
//         k++;
//     }
//     free_split_arg(split_arg);
//     return arr;
// }

// long long int *parse_arguments(int ac, char **av, int *error)
// {
//     long long int *arr;
//     int i;
//     int j = 0;
//     char **split_arg;

//     arr = allocate_array(ac);
//     if (!arr)
//         return NULL;

//     i = 1;
//     while (i < ac)
//     {
//         split_arg = ft_split(av[i], ' ');
//         arr = parse_split_arg(split_arg, arr, &j, error);
//         if (!arr)
//             return NULL;
//         i++;
//     }
//     return arr;
// }