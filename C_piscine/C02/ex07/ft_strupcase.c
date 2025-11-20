/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:45:13 by yanren            #+#    #+#             */
/*   Updated: 2024/06/19 15:45:36 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '`' && str[i] < '{')
		{
			str[i] = str[i] - 32;
		}
		else
		{
			str[i] = str[i];
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char*	re;

	if (argc > 1)
	{
		re = ft_strupcase(argv[1]);
		
		printf("%s", re);
	}
	else
	{
		printf("Please provide a string as a command-line argument.\n");
	}
	return (0);
}
*/