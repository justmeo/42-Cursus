/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 07:52:37 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/20 16:11:35 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*me;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		me = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = me;
	}
}
