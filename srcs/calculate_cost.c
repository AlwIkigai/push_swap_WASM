/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:33:17 by asyed             #+#    #+#             */
/*   Updated: 2024/05/07 20:56:02 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(t_stack *target, t_stack *stack_a, t_stack *stack_b,
		int stack_b_len)

{
	int		cost;
	float	target_len;
	float	median_a;
	float	median_b;

	cost = 0;
	target_len = (float)ft_lstsizeps(stack_a);
	median_a = target_len / 2.0;
	median_b = (float)stack_b_len / 2.0;
	if (target->index <= median_a && stack_b->index <= median_b)
		calculate_above_median_line(target, stack_b);
	else if (target->index > median_a && stack_b->index > median_b)
		calculate_below_median_line(target, stack_b, target_len, stack_b_len);
	else if (target->index <= median_a && stack_b->index > median_b)
		target_above_stack_b_below_median_line(target, stack_b, stack_b_len);
	else if (target->index > median_a && stack_b->index <= median_b)
		stack_b_below_target_above_median_line(target, stack_b, target_len);
	cost = target->total_cost;
	return (cost);
}

void	calculate_above_median_line(t_stack *target, t_stack *stack_b)

{
	if (target->index > stack_b->index)
	{
		target->total_cost = target->index;
		target->both_cost = stack_b->index;
		target->a_cost = target->total_cost - target->both_cost;
	}
	else
	{
		target->total_cost = stack_b->index;
		target->both_cost = target->index;
		target->b_cost = target->total_cost - target->both_cost;
	}
}

void	calculate_below_median_line(t_stack *target, t_stack *stack_b,
		int target_len, int stack_b_len)

{
	if (target_len - target->index > stack_b_len - stack_b->index)
	{
		target->total_cost = target_len - target->index;
		target->both_cost = stack_b_len - stack_b->index;
		target->a_cost = target->total_cost - target->both_cost;
	}
	else
	{
		target->total_cost = stack_b_len - stack_b->index;
		target->both_cost = target_len - target->index;
		target->b_cost = target->total_cost - target->both_cost;
	}
}

void	target_above_stack_b_below_median_line(t_stack *target,
		t_stack *stack_b, int stack_b_len)

{
	target->a_cost = target->index;
	target->b_cost = stack_b_len - stack_b->index;
	target->total_cost = target->a_cost + target->b_cost;
}

void	stack_b_below_target_above_median_line(t_stack *target,
		t_stack *stack_b, int target_len)

{
	target->a_cost = target_len - target->index;
	target->b_cost = stack_b->index;
	target->total_cost = target->a_cost + target->b_cost;
}
