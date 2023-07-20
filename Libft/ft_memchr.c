/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:58:18 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/19 10:08:25 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (n--)
	{
		if (*s == (unsigned char)c)
			return (s);
		++s;
	}
	return (NULL);
}

// int main()
// {
//     char str[] = "Hello World";
//     char *p = ft_memchr(str, 'o', 2);
//     printf("%s\n", p);
//     return (0);
// }