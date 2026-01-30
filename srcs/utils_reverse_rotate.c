/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:35:52 by asyed             #+#    #+#             */
/*   Updated: 2024/05/07 17:41:43 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)

{
	t_stack	*second_to_last;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		second_to_last = NULL;
		last = *stack;
		while (last->next)
		{
			second_to_last = last;
			last = last->next;
		}
		last->next = *stack;
		*stack = last;
		if (second_to_last)
		{
			second_to_last->next = NULL;
		}
	}
}

void	reverse_rotate_a(t_stack **stack_a)

{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b)

{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)

{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
