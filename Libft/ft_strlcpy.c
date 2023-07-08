/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:35:08 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/08 19:29:48 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && size > 1)
	{
		*dest++ = *src++;
		size--;
		i++;
	}
	if (size > 0)
		*dest = '\0';
	while (*src++)
		i++;
	return (i);
}

// int	main(void)
// {
// 	char source[] = "Hello, World!";
// 	char destination[10];

// 	size_t length = ft_strlcpy(destination, source, sizeof(destination));

// 	printf("Source:      %s\n", source);
// 	printf("Destination: %s\n", destination);
// 	printf("Length:      %zu\n", length);

// 	return (0);
// }