/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:03:25 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/06 12:14:03 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dst)
	{
		dst++;
		i++;
	}
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
		i++;
	}
	if (size > 0)
		*dst = '\0';
	while (*src++)
		i++;
	return (i);
}

// int main() {
//     char destination[20] = "Hello, ";
//     const char source[] = "world!";

//     size_t result = ft_strlcat(destination, source, sizeof(destination));

//     printf("Concatenated string: %s\n", destination);
//     printf("Total length: %zu\n", result);

//     return (0);
// }