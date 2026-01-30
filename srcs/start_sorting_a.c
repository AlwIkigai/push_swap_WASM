/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:35:31 by asyed             #+#    #+#             */
/*   Updated: 2024/05/07 18:53:40 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b)

{
	int	stack_len_a;

	stack_len_a = ft_lstsizeps(*stack_a);
	if (stack_len_a == 2)
		sort_two_elements(stack_a);
	else if (stack_len_a == 3)
		sort_three_elements(stack_a);
	else if (stack_len_a > 3)
		sort_stack(stack_a, stack_b);
}

void	push_elements_to_stack_b(t_stack **stack_a, t_stack **stack_b)

{
	int	stack_len_a;
	int	median;

	stack_len_a = ft_lstsizeps(*stack_a);
	median = find_median_position(stack_a);
	push_below_median(stack_a, stack_b, stack_len_a, median);
	push_remainder(stack_a, stack_b);
}

void	push_below_median(t_stack **stack_a, t_stack **stack_b, int stack_len_a,
		int median)

{
	t_stack	*current;

	current = *stack_a;
	while (stack_len_a > 3)
	{
		if (current->rank <= median)
		{
			push_b(stack_a, stack_b);
			current = *stack_a;
		}
		else
		{
			rotate_a(stack_a);
			current = *stack_a;
		}
		stack_len_a--;
	}
}

void	push_remainder(t_stack **stack_a, t_stack **stack_b)

{
	int	remainder;

	remainder = ft_lstsizeps(*stack_a);
	while (remainder > 3)
	{
		push_b(stack_a, stack_b);
		remainder--;
	}
}
