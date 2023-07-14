/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:41:18 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/14 14:21:41 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*me;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		me = (char *)malloc((1) * sizeof(char));
		me[0] = '\0';
		return (me);
	}
	me = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!me)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		me[i] = s[start];
		start++;
		i++;
	}
	me[i] = '\0';
	return (me);
}

// int	main(void)
// {
// 	const char	*original;
// 	char		*substring;

// 	original = "Hello, world!";
// 	substring = ft_substr(original, 7, 5);
// 	if (substring != NULL)
// 	{
// 		printf("Original string: %s\n", original);
// 		printf("Substring: %s\n", substring);
// 		free(substring);
// 	}
// 	return (0);
// }
