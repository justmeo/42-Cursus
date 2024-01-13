/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:35:03 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/19 10:05:26 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*v;

	v = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		v[i] = 0;
		i++;
	}
}

// int main()
// {
//     char str[50] = "8794";
// 	char str1[50] = "8794";
// 	ft_bzero(str, 2);
// 	bzero(str1, 2);
// 	printf("%s\n", str);
// 	printf("%s\n", str1);
// }