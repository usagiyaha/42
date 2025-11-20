/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:40:41 by yanren            #+#    #+#             */
/*   Updated: 2025/08/07 12:40:41 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_position(t_stack_node *a, int b_index)
{
	int				target_pos;
	int				best_match_index;
	t_stack_node	*current;

	current = a;
	best_match_index = INT_MAX;
	while (current)
	{
		if (current->index > b_index && current->index < best_match_index)
		{
			best_match_index = current->index;
			target_pos = current->pos;
		}
		current = current->next;
	}
	if (best_match_index == INT_MAX)
		target_pos = find_min_node(a)->pos;
	return (target_pos);
}

void	calculate_costs(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;

	current_position(a);
	current_position(b);
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		b->target_pos = get_target_position(a, b->index);
		if (b->target_pos <= size_a / 2)
			b->cost_a = b->target_pos;
		else
			b->cost_a = b->target_pos - size_a;
		if (b->pos <= size_b / 2)
			b->cost_b = b->pos;
		else
			b->cost_b = b->pos - size_b;
		b = b->next;
	}
}

t_stack_node	*find_cheapest_move(t_stack_node *b)
{
	t_stack_node	*cheapest;
	int				min_cost;
	int				total_cost;

	cheapest = b;
	min_cost = INT_MAX;
	while (b)
	{
		total_cost = ft_abs(b->cost_a) + ft_abs(b->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}

void	rotate_both(t_stack_node **a, t_stack_node **b,
			int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	do_move(t_stack_node **a, t_stack_node **b, int cost_a, int cost_b)
{
	rotate_both(a, b, &cost_a, &cost_b);
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
	pa(a, b);
}
