/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:09:45 by asyed             #+#    #+#             */
/*   Updated: 2023/09/27 13:09:46 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

/*
#include <stdio.h>

int main(void)
{
    // Create a list with some nodes
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");

    // Build the list
    node1->next = node2;
    node2->next = node3;

    // Get the last node
    t_list *lastNode = ft_lstlast(node1);

    // Print the content of the last node
    if (lastNode)
        printf("Last Node: %s\n", (char *)lastNode->content);
    else
        printf("List is empty.\n");

    return (0);
}
*/