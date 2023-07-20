/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:37:15 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/20 14:38:34 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	ft_putchar(unsigned int i, char *c)
// {
// 	// *c = 'a';
// 	write(1, c, 1);
// }
// int main()
// {
// 	char str[] = "Hello, world!";
// 	void (*f)(unsigned int, char *);
// 	f = &ft_putchar;
// 	ft_striteri(str, f);
// 	return (0);
// }