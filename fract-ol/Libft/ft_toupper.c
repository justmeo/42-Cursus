/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:14:47 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/08 19:29:51 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	else
		return (c);
}

// int main()
// {
//     char lowercase = 'w';
//     char uppercase = ft_toupper(lowercase);

//     printf("Lowercase character: %c\n", lowercase);
//     printf("Uppercase character: %c\n", uppercase);

//     return (0);
// }
