/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:06:58 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/18 12:02:13 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size(const char *str, char x)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str == x)
		{
			str++;
		}
		else
		{
			i++;
			while (*str != x)
			{
				str++;
				if (*str == '\0')
					return (i);
			}
		}
	}
	return (i);
}

static size_t	sizme(const char *str, char x)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str == x)
		{
			str++;
		}
		else
		{
			i++;
			while (*str != x)
			{
				str++;
				i++;
				if (*str == '\0')
					return (i);
			}
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**me;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	me = (char **)malloc(sizeof(char *) * (size(s, c) + 1));
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
			me[j] = (char *)malloc(sizeof(char) * (sizme(s, c) + 1));
			ft_strlcpy(me[j++], s + k, i - k + 1);
		}
	}
	me[j] = NULL;
	return (me);
}
