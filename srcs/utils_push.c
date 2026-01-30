/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:35:41 by asyed             #+#    #+#             */
/*   Updated: 2024/05/07 17:41:22 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **origin, t_stack **destination)

{
	t_stack	*top;

	if (*origin)
	{
		top = *origin;
		*origin = (*origin)->next;
		top->next = *destination;
		*destination = top;
	}
}

void	push_a(t_stack **stack_b, t_stack **stack_a)

{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)

{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
