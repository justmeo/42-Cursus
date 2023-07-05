/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:20:54 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/05 13:22:18 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

// int	main(void)
// {
//     char str1[20];
//     char str2[] = "yassine";
// 	printf("%s\n", ft_memmove(str1 + 3, str2, 5));
// 	printf("%s", memmove(str1 + 3, str2, 5));
// }