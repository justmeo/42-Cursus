#include "libft.h"

char *ft_itoa(int n)
{
    int me = n;
    int len =0;
    int sign = 0;

    if(me<0)
    {
        sign = 1;
        me *= -1;
        len++;
    }
    while(me > 0)
    {
        me /= 10;
        len++;
    }
    char *str = (char *)malloc((len + 1) * sizeof(char));
    if(!str) return NULL;

    me = n;
    str[len]= '\0';
    if (me < 0)
    {
        me *= -1;
        str[0] = '-';
    }
    if(me == 0) str[0]=0;
    else
    {
    int i= len -1;
    while (me > 0)
    {
        str[i] =me%10 +'0';
        me /= 10;
        i--;
    }
    }
    return str;
}

// int main()
// {
//     printf("%s",ft_itoa(   -1235));
// }