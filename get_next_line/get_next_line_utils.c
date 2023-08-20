/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:51:01 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/20 16:17:06 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (i > 0)
	{
		*me++ = (*str)[j++];
		i--;
	}
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
		return (NULL);
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
