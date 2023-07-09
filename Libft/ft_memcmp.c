/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:15:31 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/09 10:25:19 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t num)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (num--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

// int main() {
//     const char str1[] = "Hello";
//     const char str2[] = "World";
//     int result = ft_memcmp(str1, str2, sizeof(str1));

//     if (result < 0) {
//         printf("str1 is less than str2\n");
//     } else if (result > 0) {
//         printf("str1 is greater than str2\n");
//     } else {
//         printf("str1 is equal to str2\n");
//     }

//     return (0);
// }