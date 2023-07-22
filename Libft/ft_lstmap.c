/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 07:41:16 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/22 08:25:49 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	size_t	i;
	t_list	*me;
	t_list	*new;

	i = 0;
	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	me = new;
	lst = lst->next;
	while (lst)
	{
		me->next = ft_lstnew(f(lst->content));
		if (!me->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		me = me->next;
		lst = lst->next;
	}
	return (new);
}
