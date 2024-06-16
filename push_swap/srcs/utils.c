
#include "../include/push_swap.h"

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

int	is_duplicate(long long int *arr, int len, long long int num)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (arr[i] == num)
            return (1);
    }
    return (0);
}