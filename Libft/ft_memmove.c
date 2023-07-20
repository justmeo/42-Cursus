/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:20:54 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/20 16:10:49 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (s < d)
	{
		s += n;
		d += n;
		while (n--)
			*--d = *--s;
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}

// int	main(void)
// {
//    	char str1[20] = "123456";
// 	// char str2[20] = "1";
// 	// printf("memmove-->%s\n", ft_memmove(str1, str1+2, 10));
// 	printf("memmove-->%s\n", memmove(str1, str1+2, 10));
// 	// printf("%s", memmove(str1 + 3, str2, 5));
// }