

#include "../include/push_swap.h"

long long handle_overflow(t_atoll *atoll)
{
    if (atoll->sign == 1 && (atoll->result < atoll->prev_result || atoll->result / 10 != atoll->prev_result))
        return atoll->result;
    if (atoll->sign == -1 && (atoll->result > atoll->prev_result || atoll->result / 10 != atoll->prev_result))
        return atoll->result;
    return 0;
}


long long int ft_atoll(const char *str, int *error)
{
    t_atoll atoll;
    int i;

    atoll.sign = 1;
    atoll.result = 0;
    atoll.prev_result = 0;
    i = 0;

    if (str[i] == '-')
    {
        atoll.sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        atoll.prev_result = atoll.result;
        atoll.result = atoll.result * 10 + atoll.sign * (str[i] - '0');

        if (handle_overflow(&atoll))
        {
            *error = 1;
            return 0;
        }
        i++;
    }
    *error = 0;
    return atoll.result;
}