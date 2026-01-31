/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:36:01 by asyed             #+#    #+#             */
/*   Updated: 2024/05/07 17:41:00 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)

{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		last->next = first;
		*stack = first->next;
		first->next = NULL;
	}
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	emit_op("ra");
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	emit_op("rb");
}

void	rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	emit_op("rr");
}
