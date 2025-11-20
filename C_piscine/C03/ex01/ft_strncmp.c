/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:55:04 by yanren            #+#    #+#             */
/*   Updated: 2024/06/26 16:50:54 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main (void)
// {
// 	int	re;
// 	char *k = "ap";
// 	char *j = "ap";
// 	re = ft_strncmp(k, j, 4);
// 	printf("%d\n", re);
// 	printf("%d", strncmp(k, j, 4));
// }