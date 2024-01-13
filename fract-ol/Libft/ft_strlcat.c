/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:03:25 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/20 16:09:38 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if ((!dst || !src) && !size)
		return (0);
	else if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
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
	return (i + ft_strlen(src));
}

// int main() {
//     char destination[20] = "Hello, ";
//     const char source[] = "world!";

//     size_t result = ft_strlcat(destination,source,0);

//     printf("Concatenated string: %s\n", destination);
//     printf("Total length: %zu\n", result);

//     return (0);
// }