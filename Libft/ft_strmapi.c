/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:29:43 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/22 10:18:54 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*me;
	size_t	i;

	if (!s)
		return (NULL);
	me = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!me)
		return (NULL);
	i = 0;
	while (s[i])
	{
		me[i] = f(i, s[i]);
		i++;
	}
	me[i] = '\0';
	return (me);
}

char	pp(unsigned int i, char c)
{
	char	p;

	p = write(1, &c, 1);
	return p;
}

// int	main(void)
// {
// 	char	str[] = "yasfdsg fdfdss";
// 	char	(*f)(unsigned int, char);

	
// 	f = &pp;
// 	ft_strmapi(str, f);
// }
