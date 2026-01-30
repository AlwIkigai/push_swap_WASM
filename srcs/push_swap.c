/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:35:03 by asyed             #+#    #+#             */
/*   Updated: 2024/05/08 15:43:12 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "emit.h"

void init_push_swap(int argc, char **argv, void (*emit_fn)(const char *))
{
	set_emit_fn(emit_fn);

	if (argc <= 1)
		return;

	if (notdigits(&argv[1]) || gotduplicate(&argv[1]))
		firsterrorcheck();

	t_stack **stack_a = allocate_stack_a(argc, argv);
	t_stack **stack_b = allocate_stack_b();

	sort_stack_a(stack_a, stack_b);

	freenodes(stack_a);
	freenodes(stack_b);
	free(stack_a);
	free(stack_b);
}

#ifndef WASM
int	main(int ac, char *av[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		start;

	set_emit_fn(0); // Use default emit function
	if (ac <= 1)
		exit(EXIT_FAILURE);
	start = 1;
	if (notdigits(&av[start]) || gotduplicate(&av[start]))
		firsterrorcheck();
	stack_a = allocate_stack_a(ac, av);
	stack_b = allocate_stack_b();
	sort_stack_a(stack_a, stack_b);
	freenodes(stack_a);
	freenodes(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
#endif
