/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rank_one_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:34:58 by asyed             #+#    #+#             */
/*   Updated: 2024/05/07 18:52:51 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_rank_one(t_stack **stack_a)

{
	t_stack	*current;
	t_stack	*rank_one_node;

	current = *stack_a;
	rank_one_node = NULL;
	while (current != NULL)
	{
		if (current->rank == 1)
		{
			rank_one_node = current;
			break ;
		}
		current = current->next;
	}
	return (rank_one_node);
}

void	move_rank_one_up(t_stack **stack_a)

{
	int		median_a;
	int		ra;
	int		rra;
	t_stack	*rank_one;

	ra = 0;
	rra = 0;
	find_index_position(stack_a);
	rank_one = find_rank_one(stack_a);
	median_a = find_median_position(stack_a);
	if (rank_one->index <= median_a)
	{
		ra = rank_one->index;
		while (ra-- > 0)
			rotate_a(stack_a);
	}
	else
	{
		rra = ft_lstsizeps(*stack_a) - rank_one->index;
		while (rra-- > 0)
			reverse_rotate_a(stack_a);
	}
}
