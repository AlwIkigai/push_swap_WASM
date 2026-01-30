/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:36:23 by asyed             #+#    #+#             */
/*   Updated: 2023/09/26 18:36:25 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst ->next;
	}
	return (count);
}

/*
#include <stdio.h>

int main(void)
{
    // Create a sample linked list
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");

    // Build the linked list
    node1->next = node2;
    node2->next = node3;

    // Calculate and print the size of the linked list
    int size = ft_lstsize(node1);
    printf("Size of the linked list: %d\n", size);

    // Clean up: Free the memory used by the linked list
    ft_lstclear(&node1, free);

    return (0);
}
*/