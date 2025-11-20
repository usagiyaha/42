/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:29:53 by yanren            #+#    #+#             */
/*   Updated: 2024/12/04 13:16:23 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (i < n)
		{
			if (ptr1[i] != ptr2[i])
				return (ptr1[i] - ptr2[i]);
			i++;
		}
		return (0);
	}
}
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	int re;
// 	int r;
// 	re = ft_memcmp("sttt", "structure",3);
// 	r = memcmp("sttt", "structure",4);
// 	printf("%i", re);
// 	printf("%i", r);
// }