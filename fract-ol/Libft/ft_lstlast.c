/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:45:45 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/20 14:53:17 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	i = ft_lstsize(lst) - 1;
	while (i > 0)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}

// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	node1 = ft_lstnew("1");
// 	node2 = ft_lstnew("2");
// 	node3 = ft_lstnew("3");
// 	node1->next = node2;
// 	node2->next = node3;
// 	printf("%d\n", ft_lstsize(node1));
// 	ft_lstlast(node1);
// 	printf("%d\n", ft_lstsize(node1));
// }
