/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rank_in_stone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:35:09 by asyed             #+#    #+#             */
/*   Updated: 2024/05/08 13:22:17 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	confirm_rank_in_position(t_stack **stack_a)

{
	t_stack	*current;
	t_stack	*rank_in_position;
	int		stack_ranking;
	int		comparemax;

	stack_ranking = ft_lstsizeps(*stack_a);
	while (stack_ranking > 0)
	{
		current = *stack_a;
		comparemax = INT_MIN;
		while (current != NULL)
		{
			if (current->content == INT_MIN && current->rank == 0)
				current->index = 1;
			if (current->content > comparemax && current->rank == 0)
			{
				comparemax = current->content;
				rank_in_position = current;
			}
			current = current->next;
		}
		if (rank_in_position != NULL)
			rank_in_position->rank = stack_ranking;
		stack_ranking--;
	}
}
