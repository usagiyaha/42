/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:28:38 by yanren            #+#    #+#             */
/*   Updated: 2024/06/19 16:30:40 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (str[i])
	{
		if ((str[i - 1] < 'A' || str[i - 1] > 'Z')
			&& (str[i - 1] < 'a' || str[i - 1] > 'z')
			&& (str[i - 1] < '0' || str[i - 1] > '9'))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
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
		re = ft_strcapitalize(argv[1]);
		
		printf("%s", re);
	}
	else
	{
		printf("Please provide a string as a command-line argument.\n");
	}
	return (0);
}
*/