/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:10:53 by yanren            #+#    #+#             */
/*   Updated: 2024/06/24 16:49:47 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (dest[i - 1] != '\0')
		dest[i] = '\0';
	while (src[j])
		j++;
	return (j);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char buffer[100];
	int size = atoi(argv[2]);
	unsigned int length;

	if (argc > 2)
	{
		length = ft_strlcpy(buffer, argv[1], size);
		
		printf("Coppied string: %s\n", buffer);
		printf("Length of source string: %u\n", length);
	}
	else
	{
		printf("Please provide a string as a command-line argument.\n");
	}
	return (0);
}
*/