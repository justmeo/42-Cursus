/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:06:58 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/16 10:57:28 by ymrabeti         ###   ########.fr       */
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
			if (!me[j])
				return (NULL);
			ft_strlcpy(me[j], s + k, i - k + 1);
			j++;
		}
	}
	me[j] = NULL;
	return (me);
}

// static size_t	word_count(char const *s, char c)
// {
// 	size_t	count;

// 	if (*s == '\0')
// 		return (0);
// 	count = 0;
// 	while (*s && *s == c)
// 		s++;
// 	while (*s)
// 	{
// 		count++;
// 		while (*s && *s != c)
// 			s++;
// 		while (*s && *s == c)
// 			s++;
// 	}
// 	return (count);
// }

// static char	*split_string(char const *s, char c, size_t *index)
// {
// 	size_t	start;
// 	size_t	len;
// 	char	*result;

// 	start = *index;
// 	len = 0;
// 	while (s[*index] && s[*index] != c)
// 	{
// 		(*index)++;
// 		len++;
// 	}
// 	result = (char *)malloc((len + 1) * sizeof(char));
// 	if (!result)
// 		return (NULL);
// 	for (size_t i = 0; i < len; i++)
// 		result[i] = s[start + i];
// 	result[len] = '\0';
// 	return (result);
// }

// static void	free_split(char **arr, size_t size)
// {
// 	for (size_t i = 0; i < size; i++)
// 		free(arr[i]);
// 	free(arr);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	count;
// 	char	**result;
// 	size_t	index;

// 	count = word_count(s, c);
// 	result = (char **)malloc((count + 1) * sizeof(char *));
// 	if (!result)
// 		return (NULL);
// 	index = 0;
// 	for (size_t i = 0; i < count; i++)
// 	{
// 		while (s[index] && s[index] == c)
// 			index++;
// 		result[i] = split_string(s, c, &index);
// 		if (!result[i])
// 		{
// 			free_split(result, i);
// 			return (NULL);
// 		}
// 	}
// 	result[count] = NULL;
// 	return (result);
// }
// int	main(void)
// {
// 	char **tab;
// 	int i;

// 	i = 0;
// 	tab = ft_split("hello world yassine", ' ');
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	return (0);
// }