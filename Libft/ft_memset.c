/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:31:17 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/04 14:45:28 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int i;
	unsigned char *v;

	v = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		v[i] = c;
		i++;
	}
	b = v;
	return (v);
}

// #include <stdio.h>
// #include <string.h>
  
// int main()
// {
//     char str[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\nBefore memset(): %s\n", str);
  
//     // Fill 8 characters starting from str[13] with '.'
//     ft_memset(str + 13, 'f', 8*sizeof(char));
  
//     printf("After memset():  %s", str);
//     return 0;
// }