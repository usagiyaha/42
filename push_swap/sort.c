/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:40:45 by yanren            #+#    #+#             */
/*   Updated: 2025/08/07 12:40:45 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	int				largest_index;

	largest_index = find_max_node(*a)->index;
	if (is_sorted(*a))
		return ;
	if ((*a)->index == largest_index)
		ra(a);
	else if ((*a)->next->index == largest_index)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	push_all_except_three(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3 && !is_sorted(*a))
	{
		pb(b, a);
		size--;
	}
}

void	do_cheapest_move(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	calculate_costs(*a, *b);
	cheapest = find_cheapest_move(*b);
	do_move(a, b, cheapest->cost_a, cheapest->cost_b);
}

void	rotate_min_to_top(t_stack_node **a)
{
	t_stack_node	*min_node;
	int				size;
	int				min_pos;

	current_position(*a);
	min_node = find_min_node(*a);
	size = stack_size(*a);
	min_pos = min_node->pos;
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			rra(a);
	}
}

void	sort_more(t_stack_node	**a, t_stack_node **b)
{
	push_all_except_three(a, b);
	sort_three(a);
	while (*b)
		do_cheapest_move(a, b);
	rotate_min_to_top(a);
}
