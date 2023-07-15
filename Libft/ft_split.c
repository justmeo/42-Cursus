/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:06:58 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/13 08:57:21 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t *size(const char *str , char x)
{
	size_t *i =(size_t *)malloc(2 * sizeof(size_t));

	i[1] = i[0] = 0;

	while(*str)
	{
		if (*str == x)
		{
			str++;
		}
		else 
		{
			i[0]+=1;
			i[1]+=1;
			while (*str != x)
			{
				str++;
				i[1]+=1;
			}
		}
	}
	return i;
}

char	**ft_split(char const *s, char c)
{
	char	**me;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	me = (char **)malloc(sizeof(char *) * (size(s,c)[0] + 1));
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
			me[j] = (char *)malloc(sizeof(char) * (size(s,c)[1] + 1));
			if (!me[j])
				return (NULL);
			ft_strlcpy(me[j], s + k, i - k + 1);
			j++;
		}
	}
	me[j] = NULL;
	return (me);
}

int main()
{
    char **tab;
    int i;

    i = 0;
    tab = ft_split("hello world yassine", ' ');
    while (tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
    return (0);
}