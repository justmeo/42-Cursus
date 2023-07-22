/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:31:20 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/18 08:16:49 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	t_list *node1 = ft_lstnew("Hello");
// 	t_list *node2 = ft_lstnew("World");
// 	t_list *node3 = ft_lstnew("!");

// 	node1->next = node2;
// 	node2->next = node3;

// 	printf("List size: %d\n", ft_lstsize(node1));

// 	return (0);
// }
