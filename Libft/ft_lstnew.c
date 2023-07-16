/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:27:14 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/16 15:33:14 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *me;

	me = (t_list *)malloc(sizeof(t_list));
	if (!me)
		return (NULL);
	me->content = content;
	me->next = NULL;
	return (me);
}
