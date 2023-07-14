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

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (!tab)
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
			tab[j] = (char *)malloc(sizeof(char) * (i - k + 1));
			if (!tab[j])
				return (NULL);
			ft_strlcpy(tab[j], s + k, i - k + 1);
			j++;
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