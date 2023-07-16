/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:03:25 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/16 08:07:12 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	while (*dst && i < size - 1)
	{
		dst++;
		i++;
	}
	while (*src && i < size - 1)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < size)
		*dst = '\0';
	return (dst_len + src_len);
}

// int main() {
//     char destination[20] = "Hello, ";
//     const char source[] = "world!";

//     size_t result = ft_strlcat(destination, source, sizeof(destination));

//     printf("Concatenated string: %s\n", destination);
//     printf("Total length: %zu\n", result);

//     return (0);
// }