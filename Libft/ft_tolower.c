/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:39:20 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/08 19:29:50 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c += 32);
	else
		return (c);
}

// int main()
// {
//     char lowercase = 'w';
//     char uppercase = ft_tolower(lowercase);

//     printf("Lowercase character: %c\n", lowercase);
//     printf("Uppercase character: %c\n", uppercase);

//     return (0);
// }
