/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:46:19 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/20 13:42:10 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*i;
	const char	*j;

	i = (char *)dst;
	j = (const char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
		*i++ = *j++;
	return (dst);
}

// int	main(void)
// {
// 	char str1[] = "222222";
// 		char str2[] = "1";
// 	printf("mecpy-->%s", ft_memcpy(str1, str2, 10));
// 	printf("mecpy-->%s", memcpy(str1, str2, 10));
// }