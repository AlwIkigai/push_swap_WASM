/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:31:51 by asyed             #+#    #+#             */
/*   Updated: 2024/05/07 17:31:54 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
#include <stdio.h>

int main(void)
{
    // Create a new node with some data
    int data = 42;
    t_list *new_node = ft_lstnew(&data);

    // Check if the new_node was created successfully
    if (new_node)
    {
        printf("Node content: %d\n", *(int *)new_node->content);
        // You can continue to manipulate the linked list here
        // Don't forget to free the memory when you're done
        free(new_node);
    }
    else
    {
        printf("Error creating a new node\n");
    }
    return (0);
}
*/