/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:36:43 by yanren            #+#    #+#             */
/*   Updated: 2025/08/07 12:36:43 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/*header*/
# include "./libft/libft.h"

/*library*/
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*struct*/
typedef struct s_stack_node
{
	int					value;
	int					index; // rank of the value
	int					pos; // current position in stack
	int					target_pos; // where it should go in B or A
	int					cost_a; // cost to bring in top of A
	int					cost_b; // cost to bring target in top of B
	struct s_stack_node	*next;
}	t_stack_node;

/*functions*/
/*swap.c*/
// static void			swap(t_stack_node **stack);
void				sa(t_stack_node	**a);
void				sb(t_stack_node **b);
void				ss(t_stack_node **a, t_stack_node **b);

/*rotate.c*/
// static void			rotate(t_stack_node **stack);
void				ra(t_stack_node **a);
void				rb(t_stack_node **b);
void				rr(t_stack_node **a, t_stack_node **b);

/*reverse_rotate.c*/
// static void			reverse_rotate(t_stack_node **stack);
void				rra(t_stack_node **a);
void				rrb(t_stack_node **b);
void				rrr(t_stack_node **a, t_stack_node **b);

/*push.c*/
// static void			push(t_stack_node **dst, t_stack_node **src);
void				pa(t_stack_node **a, t_stack_node **b);
void				pb(t_stack_node **b, t_stack_node **a);

/*stack_utils.c*/
t_stack_node		*new_node(int value);
void				append_node(t_stack_node **stack, t_stack_node *new);
int					stack_size(t_stack_node *stack);
t_stack_node		*find_last(t_stack_node *stack);
t_stack_node		*find_min_node(t_stack_node *stack);

/*bulid_stack.c*/
// static int			is_number(char *str);
// static long			ft_atol(const char *str);
// static int			has_duplicate(t_stack_node *stack, int value);
t_stack_node		*build_stack(char **nums);

/*indexing.c*/
void				assign_index(t_stack_node *stack);
void				current_position(t_stack_node *stack);
t_stack_node		*find_max_node(t_stack_node *stack);

/*sort_utils.c*/

int					get_target_position(t_stack_node *a, int b_index);
void				calculate_costs(t_stack_node *a, t_stack_node *b);
t_stack_node		*find_cheapest_move(t_stack_node *b);
void				rotate_both(t_stack_node **a, t_stack_node **b,
						int *cost_a, int *cost_b);
void				do_move(t_stack_node **a, t_stack_node **b,
						int cost_a, int cost_b);

/*sort.c*/
void				sort_three(t_stack_node **a);
void				push_all_except_three(t_stack_node **a, t_stack_node **b);
void				do_cheapest_move(t_stack_node **a, t_stack_node **b);
void				sort_more(t_stack_node	**a, t_stack_node **b);
void				rotate_min_to_top(t_stack_node **a);

/*utils.c*/
void				free_stack(t_stack_node **stack);
void				exit_error(t_stack_node **stack);
int					ft_abs(int num);
int					is_sorted(t_stack_node *stack);
void				free_split(char **split);

/*push_swap.c*/
void				push_swap(t_stack_node **a, t_stack_node **b);

#endif