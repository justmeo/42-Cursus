/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:44:21 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/18 08:15:49 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	me;

	me = (char)c;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == me)
			return ((char *)str + i);
		--i;
	}
	return (NULL);
}

// int main()
// {
//     char *str = "Hello World";
//     char *p = ft_strrchr(str, 'o');
//     printf("%s\n", p);
//     return (0);
// }