/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:06:58 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/08 19:28:34 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_split(char const *s, char c)
{
    char **tab;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    if (!s || !(tab = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1))))
        return (NULL);
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
        {
            k = 0;
            if (!(tab[j] = (char *)malloc(sizeof(char) * (ft_len(s, c, i) + 1))))
                return (NULL);
            while (s[i] && s[i] != c)
                tab[j][k++] = s[i++];
            tab[j++][k] = '\0';
        }
    }
    tab[j] = NULL;
    return (tab);
}

// int main()
// {
//     char **tab;
//     int i;

//     i = 0;
//     tab = ft_split("hello world", ' ');
//     while (tab[i])
//     {
//         printf("%s\n", tab[i]);
//         i++;
//     }
//     return (0);
// }