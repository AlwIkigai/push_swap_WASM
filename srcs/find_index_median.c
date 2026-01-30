/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index_median.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:34:38 by asyed             #+#    #+#             */
/*   Updated: 2024/05/07 18:36:57 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	find_median_position(t_stack **stack)

{
	float	stack_len;
	float	median;

	stack_len = (float)ft_lstsizeps(*stack);
	median = stack_len / 2.0;
	return (median);
}

void	find_index_position(t_stack **stack)

{
	t_stack	*current;
	int		index;

	current = *stack;
	index = 0;
	while (current != NULL)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}
