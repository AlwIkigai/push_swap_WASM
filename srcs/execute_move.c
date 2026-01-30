/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:34:32 by asyed             #+#    #+#             */
/*   Updated: 2024/05/08 13:44:37 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_move(t_stack cheapest_target, t_stack **stack_a,
		t_stack **stack_b)

{
	float	stack_a_len;
	float	stack_b_len;
	float	median_a;
	float	median_b;

	stack_a_len = (float)ft_lstsizeps(*stack_a);
	stack_b_len = (float)ft_lstsizeps(*stack_b);
	median_a = stack_a_len / 2.0;
	median_b = stack_b_len / 2.0;
	if (cheapest_target.index <= median_a
		&& cheapest_target.target_link <= median_b)
		move_both_above_median_line(cheapest_target, stack_a, stack_b);
	else if (cheapest_target.index > median_a
		&& cheapest_target.target_link > median_b)
		move_both_below_median_line(cheapest_target, stack_a, stack_b);
	else if (cheapest_target.index <= median_a
		&& cheapest_target.target_link > median_b)
		mv_targ_abov_stac_b_belo_med_line(cheapest_target, stack_a,
			stack_b);
	else if (cheapest_target.index > median_a
		&& cheapest_target.target_link <= median_b)
		mv_stac_b_belo_targ_abov_med_line(cheapest_target, stack_a,
			stack_b);
}

void	move_both_above_median_line(t_stack cheapest_target, t_stack **stack_a,
		t_stack **stack_b)

{
	int	rr;
	int	ra;
	int	rb;

	rr = cheapest_target.both_cost;
	ra = cheapest_target.a_cost;
	rb = cheapest_target.b_cost;
	if (cheapest_target.index > cheapest_target.target_link)
	{
		while (rr-- > 0 && ft_lstsizeps(*stack_b) > 1)
			rotate_a_and_b(stack_a, stack_b);
		while (ra-- > 0)
			rotate_a(stack_a);
	}
	else
	{
		while (rr-- > 0 && ft_lstsizeps(*stack_b) > 1)
			rotate_a_and_b(stack_a, stack_b);
		while (rb-- > 0)
			rotate_b(stack_b);
	}
	push_a(stack_b, stack_a);
}

void	move_both_below_median_line(t_stack cheapest_target, t_stack **stack_a,
		t_stack **stack_b)
{
	int	rrr;
	int	rra;
	int	rrb;

	rrr = cheapest_target.both_cost;
	rra = cheapest_target.a_cost;
	rrb = cheapest_target.b_cost;
	if (ft_lstsizeps(*stack_a) - cheapest_target.index > ft_lstsizeps(*stack_b)
		- cheapest_target.target_link)
	{
		while (rrr-- > 0 && ft_lstsizeps(*stack_b) > 1)
			reverse_rotate_a_and_b(stack_a, stack_b);
		while (rra-- > 0)
			reverse_rotate_a(stack_a);
	}
	else
	{
		while (rrr-- > 0 && ft_lstsizeps(*stack_b) > 1)
			reverse_rotate_a_and_b(stack_a, stack_b);
		while (rrb-- > 0)
			reverse_rotate_b(stack_b);
	}
	push_a(stack_b, stack_a);
}

void	mv_targ_abov_stac_b_belo_med_line(t_stack cheapest_target,
		t_stack **stack_a, t_stack **stack_b)

{
	int	ra;
	int	rrb;

	ra = cheapest_target.a_cost;
	rrb = cheapest_target.b_cost;
	while (ra-- > 0)
		rotate_a(stack_a);
	while (rrb-- > 0)
		reverse_rotate_b(stack_b);
	push_a(stack_b, stack_a);
}

void	mv_stac_b_belo_targ_abov_med_line(t_stack cheapest_target,
		t_stack **stack_a, t_stack **stack_b)

{
	int	rra;
	int	rb;

	rra = cheapest_target.a_cost;
	rb = cheapest_target.b_cost;
	while (rra-- > 0)
		reverse_rotate_a(stack_a);
	while (rb-- > 0)
		rotate_b(stack_b);
	push_a(stack_b, stack_a);
}
