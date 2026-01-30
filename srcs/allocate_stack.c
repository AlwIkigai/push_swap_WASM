/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:34:21 by asyed             #+#    #+#             */
/*   Updated: 2024/05/08 16:13:02 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**allocate_stack_a(int ac, char **av)
{
	t_stack	**stack_a;

	if (ac <= 1)
		return (NULL);
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (stack_a == NULL)
		return (NULL);
	*stack_a = NULL;
	assign_nodes_to_stack_a(stack_a, ac, av);
	return (stack_a);
}

void	assign_nodes_to_stack_a(t_stack **stack_a, int ac, char **av)

{
	int		start;
	long	num;

	start = 1;
	while (start < ac)
	{
		num = ft_atol(av[start]);
		{
			if (num < INT_MIN || num > INT_MAX)
			{
				freenodes (stack_a);
				free (stack_a);
				firsterrorcheck();
			}
			ft_lstadd_back_ps(stack_a, ft_lstnewps(num));
			start++;
		}
	}
}

t_stack	**allocate_stack_b(void)

{
	t_stack	**stack_b;

	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (stack_b == NULL)
	{
		return (NULL);
	}
	*stack_b = NULL;
	return (stack_b);
}
