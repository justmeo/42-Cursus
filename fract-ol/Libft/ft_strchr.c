/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:02:02 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/18 08:15:17 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// int main()
// {
//     char *str = "Hello World";
//     char *p = ft_strchr(str, '\0');
//     printf("%s\n", p);
//     return (0);
// }