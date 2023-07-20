/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:45:56 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/20 16:34:58 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	size_t	k;

	i = 0;
	j = 0;
	if ((!haystack || !needle) && !len)
		return (0);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] && len > 0)
	{
		k = len;
		while (haystack[i] == needle[j] && k-- > 0)
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i - j);
		}
		i = i - j + 1;
		j = 0;
		len--;
	}
	return (NULL);
}

// int main() {
//     const char haystack[] = "Hello, world!";
//     const char needle[] = "\0";
//     char *found = ft_strnstr(haystack, needle, sizeof(haystack));

//     if (found != NULL) {
//         printf("Substring '%s' found at position: %ld\n", needle,
// found - haystack);
//     } else {
//         printf("Substring '%s' not found.\n", needle);
//     }

//     return (0);
// }