/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:40:07 by yanren            #+#    #+#             */
/*   Updated: 2025/08/07 12:40:07 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack_node *stack)
{
	t_stack_node	*ptr;
	t_stack_node	*min_node;
	int				index;

	index = 0;
	while (1)
	{
		ptr = stack;
		min_node = NULL;
		while (ptr)
		{
			if (ptr->index == -1 && (!min_node || ptr->value < min_node->value))
				min_node = ptr;
			ptr = ptr->next;
		}
		if (!min_node)
			break ;
		min_node->index = index++;
	}
}

void	current_position(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		i++;
		stack = stack->next;
	}
}

t_stack_node	*find_max_node(t_stack_node *stack)
{
	t_stack_node	*max_node;
	int				max_index;

	if (!stack)
		return (NULL);
	max_index = INT_MIN;
	max_node = stack;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
