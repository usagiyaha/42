/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:17:29 by yanren            #+#    #+#             */
/*   Updated: 2024/06/19 14:17:30 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] <= '/' || str[i] >= ':')
		{
			n++;
		}
		i++;
	}
	if (n > 0)
		return (0);
	else
		return (1);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	re;

	if (argc > 1)
	{
		re = ft_str_is_numeric(argv[1]);
		if (re == 0)
		{
			printf("other\n");
		}
		else
		{
			printf("numeric\n");
		}
	}
	else
	{
		printf("Please provide a string as a command-line argument.\n");
	}
	return (0);
}*/