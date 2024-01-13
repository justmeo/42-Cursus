/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:19:51 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/22 07:40:20 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main()
// {
// 	t_list *head = ft_lstnew("1");
// 	t_list *new = ft_lstnew("2");

// 	ft_lstadd_front(&head, new);

// 	while (head)
// 	{
// 		printf("%s\n",(char *)head->content);
// 		head = head->next;
// 	}
// 	return (0);
// }
