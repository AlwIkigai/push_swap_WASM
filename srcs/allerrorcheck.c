/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allerrorcheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:34:15 by asyed             #+#    #+#             */
/*   Updated: 2024/05/11 16:46:56 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	gotduplicate(char **intargs) // takes in av in full

{
	int	start;
	int	next;

	start = 0;
	while (intargs[start] != NULL && intargs[start + 1] != NULL)
	{
		next = start + 1;
		while (intargs[next])
		{
			if (ft_strcmp(intargs[start], intargs[next]) == 0)
			{
				return (1);
			}
			next++;
		}
		start++;
	}
	return (0);
}

int	notdigits(char **intargs)

{
	int	array;
	int	index;

	array = 0;
	while (intargs[array])
	{
		index = 0;
		if (intargs[array][index] == '-' && intargs[array][index + 1])
		{
			index = 1;
		}
		while (intargs[array][index])
		{
			if (intargs[array][index] < '0' || intargs[array][index] > '9')
			{
				return (1);
			}
			index++;
		}
		array++;
	}
	return (0);
}

void	firsterrorcheck(void)

{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
