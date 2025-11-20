/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:07:56 by yanren            #+#    #+#             */
/*   Updated: 2024/06/20 13:33:46 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char*	re;
	char*	des;

	if (argc > 1)
	{
		re = ft_strcpy(des,argv[1]);
		
		printf("%s", re);
	}
	else
	{
		printf("Please provide a string as a command-line argument.\n");
	}
	return (0);
}
*/