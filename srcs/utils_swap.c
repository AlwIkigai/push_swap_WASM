/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:36:07 by asyed             #+#    #+#             */
/*   Updated: 2024/05/07 17:40:49 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)

{
	t_stack	*goingdown;
	t_stack	*goingup;

	goingdown = *stack;
	goingup = (*stack)->next;
	if (goingdown && goingup)
	{
		goingdown->next = goingup->next;
		goingup->next = goingdown;
		*stack = goingup;
	}
}

void	swap_a(t_stack **stack_a)

{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)

{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b)

{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
