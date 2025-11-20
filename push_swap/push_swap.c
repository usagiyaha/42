/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:40:13 by yanren            #+#    #+#             */
/*   Updated: 2025/08/07 12:40:13 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	if (!is_sorted(*a))
	{
		if (stack_size(*a) == 2)
			sa(a);
		else if (stack_size(*a) == 3)
			sort_three(a);
		else
			sort_more(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**nums;

	b = NULL;
	a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		nums = ft_split(argv[1], ' ');
	else
		nums = argv + 1;
	a = build_stack(nums);
	push_swap(&a, &b);
	if (argc == 2)
		free_split(nums);
	free_stack(&a);
	return (0);
}

	// while (a)
	// {
	// 	ft_printf("%d, %d\n, %i,", a->value, a->index, is_sorted(a));
	// 	a = a->next;
	// }
