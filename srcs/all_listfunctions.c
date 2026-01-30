/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_listfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:34:06 by asyed             #+#    #+#             */
/*   Updated: 2024/05/07 17:34:09 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnewps(long content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->index = 0;
	new_node->rank = 0;
	new_node->current_b_target_position = -1;
	new_node->target_link = -1;
	new_node->total_cost = INT_MAX;
	new_node->both_cost = INT_MAX;
	new_node->a_cost = INT_MAX;
	new_node->b_cost = INT_MAX;
	return (new_node);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	current = *lst;
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
}

void	ft_lstprint(t_stack *lst)

{
	while (lst != NULL)
	{
		ft_printf("%d\n", lst->content);
		lst = lst->next;
	}
}

float	ft_lstsizeps(t_stack *lst)
{
	float	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	freenodes(t_stack **lst)
{
	t_stack	*current;
	t_stack	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
