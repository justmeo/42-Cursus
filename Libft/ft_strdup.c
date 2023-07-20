/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:53:07 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/18 17:12:13 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*me;

	me = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!me)
		return (NULL);
	if (me != NULL)
	{
		ft_memcpy(me, str, ft_strlen(str) + 1);
	}
	return (me);
}

// int	main(void)
// {
// 	char su[] = "yassine ";
// 	printf("%s", ft_strdup(su));
// }