/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:01:17 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/30 10:34:42 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*me;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	me = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!me)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		me[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		me[i] = s2[j];
		i++;
		j++;
	}
	me[i] = '\0';
	return (me);
}
