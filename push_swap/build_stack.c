/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:39:56 by yanren            #+#    #+#             */
/*   Updated: 2025/08/07 12:39:56 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || \
		*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

static int	has_duplicate(t_stack_node *stack, int value)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack_node	*build_stack(char **nums)
{
	int				i;
	long			num;
	t_stack_node	*stack_a;

	stack_a = NULL;
	i = 0;
	while (nums[i])
	{
		if (!is_number(nums[i]))
			exit_error(&stack_a);
		num = ft_atol(nums[i]);
		if (num < INT_MIN || num > INT_MAX || has_duplicate(stack_a, (int)num))
			exit_error(&stack_a);
		append_node(&stack_a, new_node((int)num));
		i++;
	}
	assign_index(stack_a);
	return (stack_a);
}
