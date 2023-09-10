/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:19:02 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/21 14:08:30 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *str)
{
	char	*me;
	char	*point;
	int		i;

	i = ft_strlen(str) + 1;
	if (!str)
		return (NULL);
	me = (char *)malloc((i) * sizeof(char));
	if (!me)
		return (NULL);
	point = me;
	while (i--)
		*me++ = *str++;
	return (point);
}

char	*no_need(char **str, int i)
{
	char	*me;
	char	*start;
	int		j;

	j = 0;
	me = (char *)malloc((i + 1) * sizeof(char));
	if (!me)
		return (NULL);
	start = me;
	while (i--)
		*me++ = (*str)[j++];
	*me = '\0';
	return (start);
}

char	*opp_strchr(char **str, int n)
{
	int	i;

	i = 0;
	if (!*str)
		return (NULL);
	if ((*str)[i] == '\0')
	{
		free(*str);
		*str = NULL;
		return (*str);
	}
	while ((*str)[i] != n)
	{
		if ((*str)[i] == '\0')
			return (*str);
		i++;
	}
	if ((*str)[i] == n)
		i++;
	return (no_need(str, i));
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	me;

	me = c;
	while (*str)
	{
		if (*str == me)
			return ((char *)str);
		++str;
	}
	if (me == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}
