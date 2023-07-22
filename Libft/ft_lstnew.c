/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:27:14 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/20 16:11:09 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*me;

	me = (t_list *)malloc(sizeof(t_list));
	if (!me)
		return (NULL);
	me->content = content;
	me->next = NULL;
	return (me);
}

// int	main(void)
// {
// 	int num = 42;
// 	t_list *node1 = ft_lstnew(&num);

// 	char *str = "Hello, World!";
// 	t_list *node2 = ft_lstnew(str);

// 	printf("Node 1: %d\n", *((int *)node1->content));
// 	printf("Node 2: %s\n", (char *)node2->content);

// 	return (0);
// }