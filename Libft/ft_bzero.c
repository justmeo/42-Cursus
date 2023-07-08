/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:35:03 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/08 19:25:23 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*v;

	v = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		v[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char str[50] = "yassine";
//     printf("\nBefore memset(): %s\n", str);

//     // Fill 8 characters starting from str[13] with '.'
//     ft_bzero(str + 3, 8);

//     printf("After memset():  %s", str);
//     return (0);
// }