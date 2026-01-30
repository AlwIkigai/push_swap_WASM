/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:35:15 by asyed             #+#    #+#             */
/*   Updated: 2024/05/08 13:47:42 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	cheapest_target;

	find_index_position(stack_a);
	confirm_rank_in_position(stack_a);
	if (is_sorted(*stack_a))
		return ;
	push_elements_to_stack_b(stack_a, stack_b);
	sort_three_elements(stack_a);
	while (*stack_b != NULL)
	{
		cheapest_target = find_target_and_calculate_cost(stack_a, stack_b);
		execute_move(cheapest_target, stack_a, stack_b);
	}
	move_rank_one_up(stack_a);
}
