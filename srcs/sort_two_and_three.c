/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_and_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:35:21 by asyed             #+#    #+#             */
/*   Updated: 2024/05/07 18:38:59 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elements(t_stack **stack_a)

{
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = (*stack_a)->next;
	if (first && second && (first)->content > second->content)
	{
		swap_a(stack_a);
	}
}

void	sort_three_elements(t_stack **stack_a)

{
	long	first;
	long	second;
	long	third;

	first = (long)(*stack_a)->content;
	second = (long)(*stack_a)->next->content;
	third = (long)(*stack_a)->next->next->content;
	if (first > second && second < third && first < third)
		swap_a(stack_a);
	else if (first < second && second > third && first < third)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(stack_a);
	else if (first > second && second > third && first > third)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(stack_a);
}
