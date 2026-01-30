/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_and_cost.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:34:44 by asyed             #+#    #+#             */
/*   Updated: 2024/05/08 13:53:01 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	find_target_and_calculate_cost(t_stack **stack_a, t_stack **stack_b)

{
	t_stack	*current_b;
	t_stack	*target_node;
	t_stack	cheapest_target;
	int		lowest_cost;
	int		stack_b_len;

	current_b = *stack_b;
	lowest_cost = INT_MAX;
	stack_b_len = ft_lstsizeps(*stack_b);
	while (current_b)
	{
		find_index_position(stack_a);
		find_index_position(stack_b);
		target_node = find_target_node(*stack_a, current_b);
		calculate_cost(target_node, *stack_a, current_b, stack_b_len);
		if (target_node->total_cost < lowest_cost)
		{
			lowest_cost = target_node->total_cost;
			cheapest_target = *target_node;
			cheapest_target.target_link = current_b->index;
		}
		current_b = current_b->next;
	}
	return (cheapest_target);
}
