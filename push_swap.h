/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:36:15 by asyed             #+#    #+#             */
/*   Updated: 2024/05/08 16:13:13 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*next;
	long			content;
	int				index;
	int				rank;
	int				current_b_target_position;
	int				target_link;
	int				total_cost;
	int				both_cost;
	int				a_cost;
	int				b_cost;
}					t_stack;

int					push_swap(int ac, char *av[]);

// error checks
int					gotduplicate(char **intargs);
int					notdigits(char **intargs);
void				firsterrorcheck(void);
int					is_sorted(t_stack *stack);

// additonal list functions
void				ft_lstprint(t_stack *lst);
void				freenodes(t_stack **lst);
t_stack				*ft_lstnewps(long content);
void				ft_lstadd_back_ps(t_stack **lst, t_stack *new);
float				ft_lstsizeps(t_stack *lst);

// allocate memory space
t_stack				**allocate_stack_a(int ac, char **av);
void				assign_nodes_to_stack_a(t_stack **stack_a, int ac,
						char **av);
t_stack				**allocate_stack_b(void);

// sort algorithm
void				sort_stack_a(t_stack **stack_a, t_stack **stack_b);
void				sort_two_elements(t_stack **stack_a);
void				sort_three_elements(t_stack **stack_a);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);

// find index and value in position
void				find_index_position(t_stack **stack);
void				confirm_rank_in_position(t_stack **stack_a);

// push to b operation
void				push_elements_to_stack_b(t_stack **stack_a,
						t_stack **stack_b);
void				push_below_median(t_stack **stack_a, t_stack **stack_b,
						int stack_len_a, int median);
void				push_remainder(t_stack **stack_a, t_stack **stack_b);
float				find_median_position(t_stack **stack);

// secure target to b
t_stack				find_target_and_calculate_cost(t_stack **stack_a,
						t_stack **stack_b);
t_stack				*find_target_node(t_stack *stack_a, t_stack *stack_b);
t_stack				*find_closest_bigger(t_stack *stack_a, int stack_b_rank);
t_stack				*find_smolnbr(t_stack *stack_a);

// cost analysis
int					calculate_cost(t_stack *target, t_stack *stack_a,
						t_stack *stack_b, int stack_b_len);
void				calculate_above_median_line(t_stack *target,
						t_stack *stack_b);
void				calculate_below_median_line(t_stack *target,
						t_stack *stack_b, int target_len, int stack_b_len);
void				target_above_stack_b_below_median_line(t_stack *target,
						t_stack *stack_b, int stack_b_len);
void				stack_b_below_target_above_median_line(t_stack *target,
						t_stack *stack_b, int target_len);

// execute move
void				execute_move(t_stack cheapest_target, t_stack **stack_a,
						t_stack **stack_b);
void				move_both_above_median_line(t_stack cheapest_target,
						t_stack **stack_a, t_stack **stack_b);
void				move_both_below_median_line(t_stack cheapest_target,
						t_stack **stack_a, t_stack **stack_b);
void				mv_targ_abov_stac_b_belo_med_line(t_stack cheapest_target,
						t_stack **stack_a, t_stack **stack_b);
void				mv_stac_b_belo_targ_abov_med_line(t_stack cheapest_target,
						t_stack **stack_a, t_stack **stack_b);

// final move
t_stack				*find_rank_one(t_stack **stack_a);
void				move_rank_one_up(t_stack **stack_a);

// push operation
void				push(t_stack **origin, t_stack **destination);
void				push_a(t_stack **stack_b, t_stack **stack_a);
void				push_b(t_stack **stack_a, t_stack **stack_b);

// swap operation
void				swap(t_stack **stack);
void				swap_a(t_stack **stack_a);
void				swap_b(t_stack **stack_b);
void				swap_a_and_b(t_stack **stack_a, t_stack **stack_b);

// rotate operation
void				rotate(t_stack **stack);
void				rotate_a(t_stack **stack_a);
void				rotate_b(t_stack **stack_b);
void				rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);

// reverse_rotate operation
void				reverse_rotate(t_stack **stack);
void				reverse_rotate_a(t_stack **stack_a);
void				reverse_rotate_b(t_stack **stack_b);
void				reverse_rotate_a_and_b(t_stack **stack_a,
						t_stack **stack_b);

void init_push_swap(int argc, char **argv, void (*emit_fn)(const char *));

#endif
